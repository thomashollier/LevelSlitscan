#pragma once

#include "ofMain.h"
// I tried to use a newer version of infinitecanvas but it was not working
// so I went back into the old version and edited a few things.
#include "ofxInfiniteCanvas.h"
#include "ofxGui.h"
#include "ofxXmlSettings.h"

class offsetCurve{
public:
    offsetCurve();
    
    void init(string);
    
    ofPath srcPath;
    ofPath dstPath;
    vector <ofPoint> srcPoints;
    vector <ofPoint> dstPoints;
    vector <ofPoint> srcPolyline;
    vector <ofPoint> dstPolyline;

    vector<float> tweaks;
    
    void srcPrint();
    void dstPrint();

    void updatePathFromPoints();
    void updatePointsFromPath();
    
    int selectedP;
    void selectP(ofPoint p);
    void deselectP();
    void moveSelectedP(ofPoint p);
    void insertP(ofPoint p);
    void deleteSelectedP();
    void shiftCurve(int i);
    
    void draw();

    ofImage inputImage;
    string inputImagePath;
    string sessionXMLPath;
    string outputImagePath;

    string getInputImagePath();
    string getOutputImagePath();

    void saveSession();
    void readSession(string filePath);
    void readSession();
    void newSession();
    void processNewFileSelection(ofFileDialogResult);
    void processOpenFileSelection(ofFileDialogResult);
    
    void createOffsets();
    float getOffsetFromIndex(int index);
    float getMinOffset();
    float getMaxOffset();

    void drawOffsets();
    
    float minOffset;
    float maxOffset;

};

class ofApp : public ofBaseApp{

public:
    
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseScrolled(int x, int y, float scrollX, float scrollY);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    
    void openSessionRequester();
    void newSessionRequester();
    void loadImageAndBuildScanlines();
    
    void applyOffset();
    
    string imageFile;
    void zoom(float zm);
    vector<ofPlanePrimitive> planes;
    ofImage image;
    ofxInfiniteCanvas myCanvas;
    ofxInfiniteCanvas bgCanvas;
    ofFbo bgFbo;
    void saveBgFbo();
    
    offsetCurve session;
    
    int selectedPoint;
    
    ofxPanel gui;
    
    ofxGuiGroup paramsFile;
    ofxButton _new;
    ofxButton _open;
    ofxButton _save;
    ofxButton _imageSave;

    ofParameterGroup paramsEdit;
    ofParameter <bool> _move;
    ofParameter <bool> _offset;
    ofParameter <bool> _edit;
    ofParameter <bool> _insert;
    ofParameter <bool> _remove;
    
    ofxGuiGroup paramsShow;
    ofxToggle _showCurves;
    ofxToggle _showOffset;
    ofxToggle _showMenu;
    
    void paramModeChangedEvent(ofAbstractParameter &e);
    void newClicked();
    void openClicked();
    void saveClicked();
    void imageSaveClicked();

    bool _SHIFT = false;
    void processArrowKey(char c);

    enum appMode{MOVE=0, OFFSET= 1, EDIT=2, INSERT=3, REMOVE=4};
    appMode mode;
    
};
