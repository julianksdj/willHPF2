/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class WillHPF2AudioProcessorEditor  : public juce::AudioProcessorEditor,
                                     public juce::Slider::Listener
{
public:
    WillHPF2AudioProcessorEditor (WillHPF2AudioProcessor&);
    ~WillHPF2AudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;
    //==============================================================================
    void sliderValueChanged (juce::Slider *slider) override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    WillHPF2AudioProcessor& audioProcessor;
    
    juce::Slider a1Slider;
    juce::Label a1Label;
    
    juce::Slider a0Slider;
    juce::Label a0Label;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (WillHPF2AudioProcessorEditor)
};

