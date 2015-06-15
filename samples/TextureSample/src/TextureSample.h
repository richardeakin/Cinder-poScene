#pragma once

#include "poNodeContainer.h"
#include "poShape.h"
#include "poTextBox.h"

#include "Indicator.h"


class TextureSample;
typedef std::shared_ptr<TextureSample> TextureSampleRef;

class TextureSample
: public po::scene::NodeContainer
{
public:
    static TextureSampleRef create();
    
    void setup();
    
protected:
	TextureSample();

private:
    po::scene::ShapeRef     mRectShape;     // rectangle for reference
    po::scene::ShapeRef     mEllipseShape;  // ellipse that will have texture
    po::scene::ShapeRef     mTriangleShape; // custom cinder shape
    ci::gl::TextureRef          mTexture;       // cinder texture
    
    //  Container to hold the indicators
    NodeContainerRef        mIndicatorContainer;
    NodeContainerRef        mFitIndicatorContainer;
    NodeContainerRef        mAlignIndicatorContainer;
    
    //  TextureFit types mapped to indicators
    std::vector<std::string>                mFitIndicatorNames;
    std::vector<std::string>                mAlignIndicatorNames;
    std::map<std::string, IndicatorRef>     mIndicators;
    std::map<std::string, IndicatorRef>     mFitIndicators;
    std::map<std::string, IndicatorRef>     mAlignIndicators;
    
    TextureFit::Type                        mCurrentFitType;
    Alignment                               mCurrentAlignment;
    
    void keyDown(ci::app::KeyEvent &event);
    
    void createFitIndicators();
    void createAlignmentIndicators();
    
//    void activateIndicator(int fit);
    void activateFitIndicator(int num);
    void activateAlignmentIndicator();
    
    void setFitAllImages();
    void setAlignmentAllImages();
};
