/*********************************************************************
*	Thumbnail me 2.5
*
*	Thumbnail me is a user interface for Movie thumbnailer. 
* 	Generate thumbnails from any movie is now easier !
*	
*	@package	Thumbnail me 2.5	
*	@author		Christ Azika-Eros
*	@copyright	Quentin Rousseau (c) 2010 2009, Quentin Rousseau
*	@license	Creative Commons GNU GPL
*				http://creativecommons.org/licenses/GPL/2.0/ 
*	@link 		http://thumbnailme.sourceforge.net/
*	@version	2.5
*
*	@filesource	main.cpp
*	@role	 	The beginning of the test fonction. The goal is to
*				qualify uploads of photos to http://imageshack.us/
*
*********************************************************************/
#include <QApplication>
#include "Window.hpp" 


int main(int argc, char** argv)
{
	QApplication app(argc,argv);

	Window * mainWindow = new Window();
	
	return app.exec();
}
