#############################################################################
# Makefile for building: ImageShackUploader
# Generated by qmake (2.01a) (Qt 4.7.0) on: dim. janv. 23 20:06:23 2011
# Project:  ImageShackUploader.pro
# Template: app
# Command: /opt/qtsdk-2010.05/qt/bin/qmake -o Makefile ImageShackUploader.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_NO_DEBUG -DQT_XML_LIB -DQT_GUI_LIB -DQT_NETWORK_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -m64 -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -m64 -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/opt/qtsdk-2010.05/qt/mkspecs/linux-g++-64 -I. -I/opt/qtsdk-2010.05/qt/include/QtCore -I/opt/qtsdk-2010.05/qt/include/QtNetwork -I/opt/qtsdk-2010.05/qt/include/QtGui -I/opt/qtsdk-2010.05/qt/include/QtXml -I/opt/qtsdk-2010.05/qt/include -I. -I.
LINK          = g++
LFLAGS        = -m64 -Wl,-O1 -Wl,-rpath,/opt/qtsdk-2010.05/qt/lib
LIBS          = $(SUBLIBS)  -L/opt/qtsdk-2010.05/qt/lib -lQtXml -L/opt/qtsdk-2010.05/qt/lib -lQtGui -L/usr/X11R6/lib64 -lQtNetwork -lQtCore -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /opt/qtsdk-2010.05/qt/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = ImageShackUploader.cpp \
		main.cpp \
		Window.cpp \
		ImageShackResponse.cpp \
		ImageShackObject.cpp \
		ImageShackError.cpp moc_ImageShackUploader.cpp \
		moc_Window.cpp \
		moc_ImageShackResponse.cpp \
		moc_ImageShackObject.cpp \
		moc_ImageShackError.cpp
OBJECTS       = ImageShackUploader.o \
		main.o \
		Window.o \
		ImageShackResponse.o \
		ImageShackObject.o \
		ImageShackError.o \
		moc_ImageShackUploader.o \
		moc_Window.o \
		moc_ImageShackResponse.o \
		moc_ImageShackObject.o \
		moc_ImageShackError.o
DIST          = /opt/qtsdk-2010.05/qt/mkspecs/common/g++.conf \
		/opt/qtsdk-2010.05/qt/mkspecs/common/unix.conf \
		/opt/qtsdk-2010.05/qt/mkspecs/common/linux.conf \
		/opt/qtsdk-2010.05/qt/mkspecs/qconfig.pri \
		/opt/qtsdk-2010.05/qt/mkspecs/modules/qt_webkit_version.pri \
		/opt/qtsdk-2010.05/qt/mkspecs/features/qt_functions.prf \
		/opt/qtsdk-2010.05/qt/mkspecs/features/qt_config.prf \
		/opt/qtsdk-2010.05/qt/mkspecs/features/exclusive_builds.prf \
		/opt/qtsdk-2010.05/qt/mkspecs/features/default_pre.prf \
		/opt/qtsdk-2010.05/qt/mkspecs/features/release.prf \
		/opt/qtsdk-2010.05/qt/mkspecs/features/default_post.prf \
		/opt/qtsdk-2010.05/qt/mkspecs/features/warn_on.prf \
		/opt/qtsdk-2010.05/qt/mkspecs/features/qt.prf \
		/opt/qtsdk-2010.05/qt/mkspecs/features/unix/thread.prf \
		/opt/qtsdk-2010.05/qt/mkspecs/features/moc.prf \
		/opt/qtsdk-2010.05/qt/mkspecs/features/resources.prf \
		/opt/qtsdk-2010.05/qt/mkspecs/features/uic.prf \
		/opt/qtsdk-2010.05/qt/mkspecs/features/yacc.prf \
		/opt/qtsdk-2010.05/qt/mkspecs/features/lex.prf \
		/opt/qtsdk-2010.05/qt/mkspecs/features/include_source_dir.prf \
		ImageShackUploader.pro
QMAKE_TARGET  = ImageShackUploader
DESTDIR       = 
TARGET        = ImageShackUploader

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET):  $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: ImageShackUploader.pro  /opt/qtsdk-2010.05/qt/mkspecs/linux-g++-64/qmake.conf /opt/qtsdk-2010.05/qt/mkspecs/common/g++.conf \
		/opt/qtsdk-2010.05/qt/mkspecs/common/unix.conf \
		/opt/qtsdk-2010.05/qt/mkspecs/common/linux.conf \
		/opt/qtsdk-2010.05/qt/mkspecs/qconfig.pri \
		/opt/qtsdk-2010.05/qt/mkspecs/modules/qt_webkit_version.pri \
		/opt/qtsdk-2010.05/qt/mkspecs/features/qt_functions.prf \
		/opt/qtsdk-2010.05/qt/mkspecs/features/qt_config.prf \
		/opt/qtsdk-2010.05/qt/mkspecs/features/exclusive_builds.prf \
		/opt/qtsdk-2010.05/qt/mkspecs/features/default_pre.prf \
		/opt/qtsdk-2010.05/qt/mkspecs/features/release.prf \
		/opt/qtsdk-2010.05/qt/mkspecs/features/default_post.prf \
		/opt/qtsdk-2010.05/qt/mkspecs/features/warn_on.prf \
		/opt/qtsdk-2010.05/qt/mkspecs/features/qt.prf \
		/opt/qtsdk-2010.05/qt/mkspecs/features/unix/thread.prf \
		/opt/qtsdk-2010.05/qt/mkspecs/features/moc.prf \
		/opt/qtsdk-2010.05/qt/mkspecs/features/resources.prf \
		/opt/qtsdk-2010.05/qt/mkspecs/features/uic.prf \
		/opt/qtsdk-2010.05/qt/mkspecs/features/yacc.prf \
		/opt/qtsdk-2010.05/qt/mkspecs/features/lex.prf \
		/opt/qtsdk-2010.05/qt/mkspecs/features/include_source_dir.prf \
		/opt/qtsdk-2010.05/qt/lib/libQtXml.prl \
		/opt/qtsdk-2010.05/qt/lib/libQtCore.prl \
		/opt/qtsdk-2010.05/qt/lib/libQtGui.prl \
		/opt/qtsdk-2010.05/qt/lib/libQtNetwork.prl
	$(QMAKE) -o Makefile ImageShackUploader.pro
/opt/qtsdk-2010.05/qt/mkspecs/common/g++.conf:
/opt/qtsdk-2010.05/qt/mkspecs/common/unix.conf:
/opt/qtsdk-2010.05/qt/mkspecs/common/linux.conf:
/opt/qtsdk-2010.05/qt/mkspecs/qconfig.pri:
/opt/qtsdk-2010.05/qt/mkspecs/modules/qt_webkit_version.pri:
/opt/qtsdk-2010.05/qt/mkspecs/features/qt_functions.prf:
/opt/qtsdk-2010.05/qt/mkspecs/features/qt_config.prf:
/opt/qtsdk-2010.05/qt/mkspecs/features/exclusive_builds.prf:
/opt/qtsdk-2010.05/qt/mkspecs/features/default_pre.prf:
/opt/qtsdk-2010.05/qt/mkspecs/features/release.prf:
/opt/qtsdk-2010.05/qt/mkspecs/features/default_post.prf:
/opt/qtsdk-2010.05/qt/mkspecs/features/warn_on.prf:
/opt/qtsdk-2010.05/qt/mkspecs/features/qt.prf:
/opt/qtsdk-2010.05/qt/mkspecs/features/unix/thread.prf:
/opt/qtsdk-2010.05/qt/mkspecs/features/moc.prf:
/opt/qtsdk-2010.05/qt/mkspecs/features/resources.prf:
/opt/qtsdk-2010.05/qt/mkspecs/features/uic.prf:
/opt/qtsdk-2010.05/qt/mkspecs/features/yacc.prf:
/opt/qtsdk-2010.05/qt/mkspecs/features/lex.prf:
/opt/qtsdk-2010.05/qt/mkspecs/features/include_source_dir.prf:
/opt/qtsdk-2010.05/qt/lib/libQtXml.prl:
/opt/qtsdk-2010.05/qt/lib/libQtCore.prl:
/opt/qtsdk-2010.05/qt/lib/libQtGui.prl:
/opt/qtsdk-2010.05/qt/lib/libQtNetwork.prl:
qmake:  FORCE
	@$(QMAKE) -o Makefile ImageShackUploader.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/ImageShackUploader1.0.0 || $(MKDIR) .tmp/ImageShackUploader1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/ImageShackUploader1.0.0/ && $(COPY_FILE) --parents ImageShackUploader.hpp Window.hpp ImageShackResponse.hpp ImageShackObject.hpp ImageShackError.hpp .tmp/ImageShackUploader1.0.0/ && $(COPY_FILE) --parents ImageShackUploader.cpp main.cpp Window.cpp ImageShackResponse.cpp ImageShackObject.cpp ImageShackError.cpp .tmp/ImageShackUploader1.0.0/ && (cd `dirname .tmp/ImageShackUploader1.0.0` && $(TAR) ImageShackUploader1.0.0.tar ImageShackUploader1.0.0 && $(COMPRESS) ImageShackUploader1.0.0.tar) && $(MOVE) `dirname .tmp/ImageShackUploader1.0.0`/ImageShackUploader1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/ImageShackUploader1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc_ImageShackUploader.cpp moc_Window.cpp moc_ImageShackResponse.cpp moc_ImageShackObject.cpp moc_ImageShackError.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_ImageShackUploader.cpp moc_Window.cpp moc_ImageShackResponse.cpp moc_ImageShackObject.cpp moc_ImageShackError.cpp
moc_ImageShackUploader.cpp: ImageShackError.hpp \
		ImageShackObject.hpp \
		ImageShackResponse.hpp \
		ImageShackUploader.hpp
	/opt/qtsdk-2010.05/qt/bin/moc $(DEFINES) $(INCPATH) ImageShackUploader.hpp -o moc_ImageShackUploader.cpp

moc_Window.cpp: ImageShackUploader.hpp \
		ImageShackError.hpp \
		ImageShackObject.hpp \
		ImageShackResponse.hpp \
		Window.hpp
	/opt/qtsdk-2010.05/qt/bin/moc $(DEFINES) $(INCPATH) Window.hpp -o moc_Window.cpp

moc_ImageShackResponse.cpp: ImageShackObject.hpp \
		ImageShackResponse.hpp
	/opt/qtsdk-2010.05/qt/bin/moc $(DEFINES) $(INCPATH) ImageShackResponse.hpp -o moc_ImageShackResponse.cpp

moc_ImageShackObject.cpp: ImageShackObject.hpp
	/opt/qtsdk-2010.05/qt/bin/moc $(DEFINES) $(INCPATH) ImageShackObject.hpp -o moc_ImageShackObject.cpp

moc_ImageShackError.cpp: ImageShackError.hpp
	/opt/qtsdk-2010.05/qt/bin/moc $(DEFINES) $(INCPATH) ImageShackError.hpp -o moc_ImageShackError.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all:
compiler_uic_clean:
compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean 

####### Compile

ImageShackUploader.o: ImageShackUploader.cpp ImageShackUploader.hpp \
		ImageShackError.hpp \
		ImageShackObject.hpp \
		ImageShackResponse.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ImageShackUploader.o ImageShackUploader.cpp

main.o: main.cpp Window.hpp \
		ImageShackUploader.hpp \
		ImageShackError.hpp \
		ImageShackObject.hpp \
		ImageShackResponse.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

Window.o: Window.cpp Window.hpp \
		ImageShackUploader.hpp \
		ImageShackError.hpp \
		ImageShackObject.hpp \
		ImageShackResponse.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Window.o Window.cpp

ImageShackResponse.o: ImageShackResponse.cpp ImageShackResponse.hpp \
		ImageShackObject.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ImageShackResponse.o ImageShackResponse.cpp

ImageShackObject.o: ImageShackObject.cpp ImageShackObject.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ImageShackObject.o ImageShackObject.cpp

ImageShackError.o: ImageShackError.cpp ImageShackError.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ImageShackError.o ImageShackError.cpp

moc_ImageShackUploader.o: moc_ImageShackUploader.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_ImageShackUploader.o moc_ImageShackUploader.cpp

moc_Window.o: moc_Window.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_Window.o moc_Window.cpp

moc_ImageShackResponse.o: moc_ImageShackResponse.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_ImageShackResponse.o moc_ImageShackResponse.cpp

moc_ImageShackObject.o: moc_ImageShackObject.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_ImageShackObject.o moc_ImageShackObject.cpp

moc_ImageShackError.o: moc_ImageShackError.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_ImageShackError.o moc_ImageShackError.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:
