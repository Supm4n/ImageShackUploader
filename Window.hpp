/*********************************************************************
*	Thumbnail me 2.5
*
*	Thumbnail me is a user interface for Movie thumbnailer. 
* 	Generate thumbnails from any movie is now easier !
*	
*	@package	Thumbnail me 2.5	
*	@author		Christ Azika-Eros <christ@azika-eros.org>
*	@copyright	Quentin Rousseau (c) 2010 2009, Quentin Rousseau
*	@license	Creative Commons GNU GPL
*				http://creativecommons.org/licenses/GPL/2.0/ 
*	@link 		http://thumbnailme.sourceforge.net/
*	@version	2.5
*
*	@filesource	Window.hpp
*	@role	 	The header of the Window class. 
*				This class create the main widget. Tests are made
*				through this widget.
*
*********************************************************************/
#ifndef  HEADER_WINDOW
#define  HEADER_WINDOW

#include <QDebug>
#include <QNetworkProxy>
#include <QTimer>
#include <QWidget>

#include "ImageShackObject.hpp"
#include "ImageShackUploader.hpp"
#include "ImageShackError.hpp"


/**
* 	Window  Class	
*	
*	@author Christ Azika-Eros <christ@azika-eros.org>
**/
class Window : public QObject
{
    Q_OBJECT

	public  : // public methods

			/**
			*	Constructor
			*
			*	@param QWidget parent	The parent Widget
			**/
			Window();

			/**
			*	Destructor
			**/
			~Window();

	private : // Private objects or variables


			/**
			*	Uploader to ImageShack	
			**/
            ImageShackUploader * uploader;

			QList<ImageShackObject *>  listeImages ;

			QList<ImageShackObject *>  listeImages2 ;

			bool secondUpload;

    private slots :

            /**
            *	Manage Response
            *
            **/
            void manageResponse(bool response);

            void manageEndUpload();

			void oneUploadDone(ImageShackResponse * reponse);

			void handleErrors(ImageShackError::UploadError);

			void handleProgressions(ImageShackObject * fic, qint64 rec, qint64 total);
};

#endif
