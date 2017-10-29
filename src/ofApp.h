#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void draw();
	
    int cols, rows;
    int scl = 20;
    int w = 1200;
    int h = 900;
    
    float flying = 0;
    
    ofPolyline triangle;
    
    struct Terrain {
        ofPoint pos;
    };
    
    vector<Terrain> t;
    
    
};
