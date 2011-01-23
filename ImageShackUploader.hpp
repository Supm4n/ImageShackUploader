/*********************************************************************
*	Thumbnail me 3.0
*
*	Thumbnail me is a user interface for Movie thumbnailer. 
* 	Generate thumbnails from any movie is now easier !
*	
*	@package	Thumbnail me 3.0	
*	@author		Christ Azika-Eros <christ@azika-eros.org>
*	@copyright	Quentin Rousseau (c) 2010 2009, Quentin Rousseau
*	@license	Creative Commons GNU GPL
*				http://creativecommons.org/licenses/GPL/2.0/ 
*	@link 		http://thumbnailme.sourceforge.net/
*	@version	3.0
*
*	@filesource	ImageShackUploader.hpp
*	@role	 	The header of the ImageShackUploader class. 
*				This class creates the object which will upload
*				photos to ImageShack.
*
*********************************************************************/
#ifndef  HEADER_IMAGESHACKUPLOADER
#define  HEADER_IMAGESHACKUPLOADER

#include <QByteArray>
#include <QDebug>
#include <QFile>
#include <QFileInfo>
#include <QHash>
#include <QHashIterator>
#include <QImage>
#include <QMimeData>
#include <QNetworkAccessManager>
#include <QNetworkProxy>
#include <QNetworkReply>
#include <QString>
#include <QStringList>
#include <QUrl>
#include <QWidget>
 
#include "ImageShackError.hpp"
#include "ImageShackObject.hpp"
#include "ImageShackResponse.hpp"

/**
* 	ImageShackUploader Class	
*	
*	@author Christ Azika-Eros <christ@azika-eros.org>
**/
class ImageShackUploader : public QObject
{
	Q_OBJECT


    //public  : // variables, enums


    public  : // Public methods

			/**
			*	Constructor
			*
			*	QString developerKey		the developer key received 
			*		      			    	to use APIs
			*	@param  QWidget * parent	the parent Widget
			*	@access public
			**/
            ImageShackUploader(QString         developerKey =  ""  ,
                               QString         userName     =  ""  ,
                               QString         userPassword =  ""  ,
                               QNetworkProxy * proxy		= NULL );

			/**
			*	Destructor
			*
			*	@access	public
			**/
            ~ImageShackUploader(void);

            /**
            *	Upload a list of images
            *
            *	QList<ImageShackObject> images	     images to upload
            *   QString                 userName     the user name
            *	QString				    userPassword the user password
            *
            *	@access public
            */
            void uploadImages(QList<ImageShackObject *> images        ,
                             QString                userName = ""     ,
                             QString 			    userPassword = "");

            /**
            *	set proxy variable to NULL in order to not
            *	use any proxy when uploading
            *
			*	@access public	
			*/
            void noProxy();

            /**
            *	check wether the user password is correct
            *
            *	@return bool true if the password is correct, false if
            *				 not
            */
            void checkUserPassword(QString	userName     ,
                                   QString   userPassword);

    signals : // Signals

            /**
			*	Send the result of the upload	
            *
            *	@param  QString fileUploaded	the file uploaded
			*	@param	QHash<QString, QString> informations concerning	
			*								    the uploads
			*	@access	public	
			*/
            void uploadDone(ImageShackResponse * uploadResponse);


            void endOfUploads();

            void uploadAlreadyStarted();

            /**
            *	Send the progression of the upload
            *
            *	@param QString fileUploaded the file uploaded
            *	@param qint64 bytesReceived	bytes received
            *	@param qint64 bytesTotal	total bytes to send
            *
            *	@access public
            **/
            void uploadProgress(ImageShackObject * fileUploaded, qint64 bytesReceived, qint64 bytesTotal);

            /**
            *	Send the upload error
            *
            *	@param UploadError error the error
            **/
            void uploadError(ImageShackError::UploadError error);

            /**
            *	@see QNetworkAccessManager signal
            *
            **/
            void authentificationRequired(QNetworkReply  * reply,
                                          QAuthenticator * authentificator);

            /**
            *	@see QNetworkAccessManager signal
            *
            **/
            void proxyAuthentificationRequired(const QNetworkProxy & proxy,
                                               QAuthenticator      * authenticator);

            /**
            *	The authentification response
            *
            **/
            void authentificationResponse(bool response);

	private : // Private objects or variables

            QList<ImageShackObject *> filesToUpload;
            /**
            *	QString fileBeingUploaded the file being uploading
            *
            *	@access private
            **/
            ImageShackObject * fileBeingUploaded;

            /**
			*	QString imageUploadUrl	The entry point to upload 
			*						    images to ImageShack
			*	@access private
			**/
            QString imageUploadUrl;

            /**
            *	QString authentificationUrl the url to test the user password
            *	http://www.imageshack.us/auth.php?username=kwentakill&password=rousseau
            *
            **/
            QString authentificationUrl;

			/**
			*	bool	removeInformationBar boolean to leave/remove
			*			    				 information bar on the thumbnail
			*			    				 image generated by ImageShack	
			*	@access	private
			**/	
			bool	removeInformationBar;

            /**
            *	bool uploadInProgress	equals true when a file is being uploaded.
            *							no upload can start in this case
            *
            *	@access	private
            **/
            bool	uploadStarted;

            /**
			*	QNetworkAccessManager	networkManager	the network manager	
			*
			*	@access	private
			**/	
			QNetworkAccessManager * networkManager;

			/**
			*	QNetworkProxy		the	proxy to use when uploading
			*
			*	@access private
			**/
			QNetworkProxy * proxy;

			/**
			*	QNetworkReply	response	ImageShack response
			*
			*	@access private
			**/	
			QNetworkReply * response;	

			/**
			*	QString developerKey	the developer key received 
			*		      			    to use APIs
			*	@access private
			**/	
			QString developerKey;	

			/**
			*	QString	userName	the user name. Only required to upload
			*						to a specific account (userUploadImage)
			*	@access	private
			**/
			QString userName;
		
			/**
			*	QString	userPassword	the user password. Only required to 
			*							upload to a specific account 
			*							(userUploadImage)
			*	@access	private
			**/
            QString userPassword;

            int nbFilesToUploads;

            int nbFilesUploaded;

	private slots : // private slots	

            /**
			*	Manage replies after the image is uploaded
			*
			*	@access private	
            **/
			void imageUploaded();

            /**
            *	Manage image uploads
            *
            *	@param  QString fileUploaded	the file uploaded
            *	@param	QHash<QString, QString> informations concerning
            *								    the uploads
            *	@access	private
            */
            void manageMultiUploads(ImageShackResponse * uploadResponse);

            /**
            *	manage authentification requirements
            *
            **/
            void manageAuthentificationRequired(QNetworkReply  * reply,
                                                QAuthenticator * authentificator);

            /**
            *	manage proxy authentification requirements
            *
            **/
            void manageProxyAuthentificationRequired(const QNetworkProxy & proxy,
                                                     QAuthenticator      * authenticator);

            /**
            *	manage authentification response
            *
            **/
            void manageAuthentificationResponse();

            /**
			*	Manage upload errors 
			*
			*	@access private	
            **/
            void manageUploadError(QNetworkReply::NetworkError errorCode);

            /**
            *	Manage the upload progression
            *
            *	@access private
            **/
            void manageUploadProgress(qint64 bytesReceived,qint64 bytesTotal);

	private : // private methods
			
            /**
            *	Upload an image to an account
            *
            *	@param	QString imagePath	    the image path
            *	@param	QString tags	        image tags
            *	@param	QString resizeOption	the resize option,
            *									default value is resample
            *	@param	QString user		    the user ident
            *	@param	QString password	    the user password
            *	@access	private
            */
            void uploadOneImage(ImageShackObject *   image        , 
                                QString	userName     = ""         ,
                                QString userPassword = ""        );

            /**
			*	Upload an image. This method is called by 
			*	userUploadImage and anonymousUploadImage
			*	methods	
			*
			*	@access private	
			*/
            void sendImage(ImageShackObject *     imageToUpload,
                           QHash<QString, QString>   headers  );

            /**
            *	Return the mimetype basing on the file extension
            *
            *	@access private
            */
            QString mimeType(QString imagePath);

            /**
            *	Return the mimeType list
            *
            *	@access private
            */
            QHash<QString, QStringList> mimeTypeList();


            /**
            *	Manage image uploads
            *
            *	@param  QString fileUploaded	the file uploaded
            *	@param	QHash<QString, QString> informations concerning
            *								    the uploads
            *	@access	private
            */
            void manageMultiUplaods(ImageShackResponse * uploadResponse);

	public  : // Setters and Getters

			/**
			*	the getter of the boolean removeInformationBar	
			*		
			*	@return removeInformationBar
			*	@access public	
			*/
			bool getRemoveInformationBar();

			/**
			*	the getter of the proxy
			*
			*	@return * QNetworkProxy
			*	@access	  public
			*/
			QNetworkProxy * getProxy();

			/**
			*	the getter of developerKey 
			*		
			*	@return developerKey
			*	@access public	
			*/
			QString getDeveloperKey();

			/**
			*	the getter of imageUploadUrl
			*		
			*	@return developerKey
			*	@access public	
			*/
			QString getImageUploadUrl();

			/**
			*	the getter of userName 
			*		
			*	@return userName
			*	@access public	
			*/
			QString getUserName();

			/**
			*	the getter of userPassword 
			*		
			*	@return userPassword
			*	@access public	
			*/
			QString getUserPassword();

			/**
			*	the setter of developerKey
			*		
			*	@param  developerKey	the developer key needed to upload
			*							to unified ImageShack API
			*	@access	public	
			*/
			void setDeveloperKey(QString developerKey);

			/**
			*	the setter of imageUploadUrl
			*		
			*	@param  developerKey	The entry point to upload 
			*							images to ImageShack
			*	@access	public	
			*/
			void setImageUploadUrl(QString imageUploadUrl);

			/**
			*	the setter of the proxy use to upload
			*
			*	@param  QNetworkProxy	the proxy to use
			* 	@access public
			*/
			void setProxy(QNetworkProxy * proxy);
			
			/**
			*	the setter of imageEntryUpload 
			*		
			*	@param	removeInformationBar	 the boolean to remove/leave 
			*			    					 the information bar from
			*			 	     				 thumbnails
			*	@access	public				 
			*/
			void setRemoveInformationBar(bool removeInformationBar);

			/**
			*	the setter of userName
			*		
			*	@param	userName	the user name
			*	@access	public	
			*/
			void setUsername(QString userName);

			/**
			*	the setter of userPassword 
			*		
			*	@param	userPassword	the user password
			*	@access	public	
			*/
			void setUserPassword(QString userPassword);
};

#endif // HEADER_IMAGESHACKUPLOADER
