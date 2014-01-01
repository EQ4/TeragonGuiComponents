/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic startup code for a Juce application.

  ==============================================================================
*/

#ifndef PLUGINPROCESSOR_H_INCLUDED
#define PLUGINPROCESSOR_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginParameters.h"

namespace teragon {

class TeragonPluginBase : public AudioProcessor {
public:
    TeragonPluginBase();
    virtual ~TeragonPluginBase() {}

    // Playback ////////////////////////////////////////////////////////////////////
    virtual void prepareToPlay(double sampleRate, int samplesPerBlock);
    virtual void processBlock(AudioSampleBuffer &buffer, MidiBuffer &midiMessages);
    virtual void releaseResources();

    // Plugin properties ///////////////////////////////////////////////////////////
    virtual const String getName() const = 0;
    virtual bool acceptsMidi() const;
    virtual bool producesMidi() const;
    virtual bool isInputChannelStereoPair(int index) const { return true; }
    virtual bool isOutputChannelStereoPair(int index) const { return true; }
    virtual bool silenceInProducesSilenceOut() const { return true; }
    virtual double getTailLengthSeconds() const { return 0.0; }
    virtual const String getInputChannelName(int index) const { return String(index + 1); }
    virtual const String getOutputChannelName(int index) const { return String(index + 1); }

    // Editor //////////////////////////////////////////////////////////////////////
    virtual AudioProcessorEditor *createEditor() = 0;
    virtual bool hasEditor() const { return true; }

    // Parameter handling //////////////////////////////////////////////////////////
    virtual int getNumParameters();
    virtual float getParameter(int index);
    virtual void setParameter(int index, float newValue);
    virtual const String getParameterName(int index);
    virtual const String getParameterText(int index);
    virtual bool isMetaParameter(int parameterIndex) const;

    // Program handling ////////////////////////////////////////////////////////////
    virtual int getNumPrograms() { return 0; }
    virtual int getCurrentProgram() { return 0; }
    virtual void setCurrentProgram(int index) {}
    virtual const String getProgramName(int index) { return String::empty; }
    virtual void changeProgramName(int index, const String &newName) {}

    // State save/restore //////////////////////////////////////////////////////////
    virtual void getStateInformation(MemoryBlock &destData);
    virtual void setStateInformation(const void *data, int sizeInBytes);

protected:
    ConcurrentParameterSet parameters;
};

} // namespace teragon

#endif  // PLUGINPROCESSOR_H_INCLUDED
