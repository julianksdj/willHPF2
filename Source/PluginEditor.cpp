/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
WillHPF2AudioProcessorEditor::WillHPF2AudioProcessorEditor (WillHPF2AudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    setSize (400, 300);
    addAndMakeVisible(a1Slider);
    a1Slider.setRange (-1.0, 1.0);
    a1Slider.addListener (this);
    addAndMakeVisible (a1Label);
    a1Label.setText ("a1 cofficient", juce::dontSendNotification);
    a1Label.attachToComponent (&a1Slider, true);
    
    addAndMakeVisible(a0Slider);
    a0Slider.setRange (-1.0, 1.0);
    a0Slider.addListener (this);
    addAndMakeVisible (a0Label);
    a0Label.setText ("a0 cofficient", juce::dontSendNotification);
    a0Label.attachToComponent (&a0Slider, true);
}

WillHPF2AudioProcessorEditor::~WillHPF2AudioProcessorEditor()
{
}

//==============================================================================
void WillHPF2AudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (30.0f);
    g.drawFittedText ("Will Pirkle - Simple HPF 2", 0, 30, getWidth(), 5, juce::Justification::centred, 1);
    g.setFont (15.0f);
    g.drawFittedText ("y(n) = a0 * x(n) + a1 * x(n-1)", 0, 60, getWidth(), 5, juce::Justification::centred, 1);
}

void WillHPF2AudioProcessorEditor::resized()
{
    a1Slider.setBounds(100,140,250,20);
    a0Slider.setBounds(100,160,250,20);
}


void WillHPF2AudioProcessorEditor::sliderValueChanged (juce::Slider *slider)
{
    if (slider == &a1Slider)
    {
        audioProcessor.setA1(a1Slider.getValue());
    }
    if (slider == &a0Slider)
    {
        audioProcessor.setA0(a0Slider.getValue());
    }
    
}

