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
    QList<ImageShackObject *>  listeImages ;

    //ImageShackObject * howard = new ImageShackObject("/home/christ/Images/design/0pc.png","mc,notmac,pub",true);
    //ImageShackObject * dunk   = new ImageShackObject("/home/christ/Images/design/1biere.png","biere,pub",true);
    //ImageShackObject * fire   = new ImageShackObject("/home/christ/Images/design/3plus.png","plus,priv",false);
    //ImageShackObject * a      = new ImageShackObject("/home/christ/Images/design/4cpu.png","cpu,priv",false);

    //listeImages << howard;
    //listeImages << dunk;
    //listeImages << fire;
    //listeImages << a;

    ImageShackObject * basket = new ImageShackObject("/home/christ/Images/Basket/basket.jpg","basket,fire,pub",true);
    ImageShackObject * dunk   = new ImageShackObject("/home/christ/Images/Basket/dunk.jpg","dunk,nba,priv",false);

    listeImages << basket;
    listeImages << dunk;

    uploader = new ImageShackUploader(QString("EFI0O4JZd1897eb3d86758fa0ee582a34385405e"));
   // uploader->anonymousUploadImages(listeImage);
    uploader->uploadImages(listeImages,"kwentakill","rousseau");
    //uploader->anonymousUploadImage(fichier,"basket");
	//uploader->setRemoveInformationBar(false);	
    //uploader->userUploadImage(fichier,"kwentakill","rousseau","dunk");
    //uploader->userUploadImage(fichier,"kwentakill","rousea","dunk","150x150");

    //uploader->checkUserPassword("kwentakill","rousseau");

    connect(uploader,SIGNAL(authentificationResponse(bool)),this,SLOT(manageResponse(bool)));
    connect(uploader,SIGNAL(endOfUploads()),this,SLOT(manageEndUpload()));
}

void Window::manageEndUpload()
{
    qDebug() << "End of uploads" ;
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
