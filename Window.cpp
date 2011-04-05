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
*	@filesource	Window.cpp
*	@role	 	The definition of the Window class. 
*				This class create the main widget. Tests are made
*				through this widget.
*
*********************************************************************/
#include "Window.hpp"

/**
*	Constructor
*
*	@param QWidget parent	The parent Widget
**/
Window::Window()
{
	this->secondUpload = false;
    //QList<ImageShackObject *>  listeImages ;
	QNetworkProxy * proxy = new QNetworkProxy(QNetworkProxy::HttpProxy,QString("proxy.rennes.enst-bretagne.fr"),3128);

    ImageShackObject * pc = new ImageShackObject("/home/christ/Images/design/0pc.png","mc,notmac,pub",true);
    ImageShackObject * biere   = new ImageShackObject("/home/christ/Images/design/1biere.png","biere,pub",true);
    ImageShackObject * plus  = new ImageShackObject("/home/christ/Images/design/3plus.png","plus,priv",false);
    ImageShackObject * cpu      = new ImageShackObject("/home/christ/Images/design/4cpu.png","cpu,priv",false);

    listeImages << pc;
    listeImages << pc;
    listeImages << pc;
    listeImages2 << biere;
    listeImages2 << plus;
    listeImages2 << cpu;
    //listeImages << fire;
    //listeImages << a;

    //ImageShackObject * basket = new ImageShackObject("/home/christ/Images/Basket/basket.jpg","basket,fire,pub",true);
    //ImageShackObject * dunk   = new ImageShackObject("/home/christ/Images/Basket/test.jpg","dunk,nba,priv",false);

	//basket->setResizeOption("200x200");
	//dunk->setResizeOption("50x300");

    //listeImages << dunk;
   // listeImages << basket;

    uploader = new ImageShackUploader(QString("EFI0O4JZd1897eb3d86758fa0ee582a34385405e"));
	uploader->setProxy(proxy);

	//uploader->checkUserPassword(QString("kwentakill"),QString("rousseau"));

   //uploader->anonymousUploadImages(listeImage);
	qDebug() << "Window.cpp : Nombre de fichiers =" << listeImages.size();
    uploader->uploadImages(listeImages,"kwentakill","rousseau");

	//QTimer::singleShot(500, this, SLOT(oneUploadDone()));

    //uploader->anonymousUploadImage(fichier,"basket");
	//uploader->setRemoveInformationBar(false);	
    //uploader->userUploadImage(fichier,"kwentakill","rousseau","dunk");
    //uploader->userUploadImage(fichier,"kwentakill","rousea","dunk","150x150");

    //uploader->checkUserPassword("kwentakill","rousseau");
    connect(uploader,SIGNAL(authentificationResponse(bool)),this,SLOT(manageResponse(bool)));
	connect(uploader,SIGNAL(uploadDone(ImageShackResponse *)),this,SLOT(oneUploadDone(ImageShackResponse *)));
    connect(uploader,SIGNAL(endOfUploads()),this,SLOT(manageEndUpload()));
	connect(uploader,SIGNAL(uploadError(ImageShackError::UploadError)),this,SLOT(handleErrors(ImageShackError::UploadError)));
	connect(uploader,SIGNAL(uploadProgress(ImageShackObject *,qint64,qint64)),this,SLOT(handleProgressions(ImageShackObject *,qint64,qint64)));


}

void Window::handleErrors(ImageShackError::UploadError code)
{
	qDebug() << "Window.cpp : Error n° " << code;
}
void Window::oneUploadDone(ImageShackResponse * response)
{
	//qDebug() << "Window.cpp : Reponse received " << response->getImageShackResponse();
	qDebug() << "Window.cpp : Reponse received " ;
	qDebug() << "" ;
//	uploader->abortUploads();
}

void Window::handleProgressions(ImageShackObject * fic, qint64 rec, qint64 total)
{
    qDebug() << fic->getObjectPath() << "Window.cpp : Uploading " << rec << "/"<< total;
}

void Window::manageEndUpload()
{
    //qDebug() << "End of uploads" ;
	if(this->secondUpload == false)
	{
		this->secondUpload = true;
		qDebug() << "Window.cpp : End of uploads____________________________________________";
		uploader->uploadImages(listeImages2,"kwentakill","rousseau");
	}
}
/**
*	Destructor
**/
Window::~Window()
{

}

void Window::manageResponse(bool response)
{
    if(response)
        qDebug() << "Good Password !!"  ;
    else
        qDebug() << "Wrong password";
}
