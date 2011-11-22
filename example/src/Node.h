/*
 *  Node.h
 *  emptyExample
 *
 *  Created by 森 浩一郎 on 11/03/22.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */


#include "ofMain.h"


class mNode : public ofNode {
	
public:
	
	int mID;
	
	ofQuaternion mOrientation;
	
	void customDraw() {
        
        ofSetColor(255,255,255);
		glPushMatrix();
		glScalef(10, 10, 10);
        if(mID == 0){
            ofNoFill();
            ofSphere(0, 0, 0, 635.6752);
        }else{
            ofSphere(0, 0, 0, 10);
        }
		glPopMatrix();		
	}
    
};

