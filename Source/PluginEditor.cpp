/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
KadenzePlugin1AudioProcessorEditor::KadenzePlugin1AudioProcessorEditor (KadenzePlugin1AudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);
    
    //Here's the slider being drawn
    
    auto& params = processor.getParameters();
    AudioParameterFloat* gainParameter = (AudioParameterFloat*)params.getUnchecked(0);


    
    mGainControlSlider.setBounds(0, 0, 100, 100);
    mGainControlSlider.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
    mGainControlSlider.setTextBoxStyle(Slider::NoTextBox, true, 0, 0);
    mGainControlSlider.setRange(gainParameter->range.start, gainParameter->range.end); //set slider range
    mGainControlSlider.setValue(*gainParameter); //set the initial value of the slider to be the same as the default value of the gain parameter
    mGainControlSlider.addListener(this);
    addAndMakeVisible(mGainControlSlider);
    
}

KadenzePlugin1AudioProcessorEditor::~KadenzePlugin1AudioProcessorEditor()
{
}

//==============================================================================
void KadenzePlugin1AudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));

    g.setColour (Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("Hello World!", getLocalBounds(), Justification::centred, 1);
}

void KadenzePlugin1AudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}

void KadenzePlugin1AudioProcessorEditor::sliderValueChanged (Slider* slider)
{
    
    auto& params = processor.getParameters();
    
    if (slider == &mGainControlSlider) {
        
        AudioParameterFloat* gainParameter = (AudioParameterFloat*)params.getUnchecked(0);
        *gainParameter = mGainControlSlider.getValue();
        
        DBG("GAIN SLIDER HAS CHANGED");
        
    }
    
    DBG("SLIDER VALUE CHANGED");
    
}
