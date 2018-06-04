#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){
	ofGLFWWindowSettings settings;
    settings.setGLVersion(4, 5); //we define the OpenGL version we want to use
    settings.width = 1280;
    settings.height = 720;
    settings.numSamples = 4;
    // settings.windowMode = OF_FULLSCREEN;
    // settings.windowMode = OF_GAME_MODE;
    settings.windowMode = OF_WINDOW;
    // settings.multiMonitorFullScreen = true;
    ofCreateWindow(settings);
    // this kicks off the running of my app
    ofRunApp(new ofApp());

}
