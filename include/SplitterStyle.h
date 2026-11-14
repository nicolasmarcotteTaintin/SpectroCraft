/*
 * SplitterStyle.h - one look for every draggable separator in the app.
 *
 * The bar between the waveform and the spectrogram, the one between the video
 * image and the video tracks, and the one between the table list and its
 * preview plot are all the same thing: a 6 px bar with a short grip of three
 * lines in the middle. They used to draw their own grips (one a long dotted
 * line, one five dots), which read as three different widgets.
 */
#pragma once

#include <JuceHeader.h>

namespace sc::ui
{
    /* Thickness of every separator bar. A drag target you can actually hit,
       small enough not to eat the tracks. */
    inline constexpr int kSplitterH = 6;

    inline juce::Colour splitterFill()   { return juce::Colour::fromRGB (40, 40, 44); }
    inline juce::Colour splitterGrip()   { return juce::Colour::fromRGB (110, 110, 120); }

    /** Draw the grip in the middle of `area`. `vertical` = a bar that splits
        left/right (its lines are horizontal); false = a bar that splits
        top/bottom (its lines are vertical). */
    inline void drawSplitterGrip (juce::Graphics& g, juce::Rectangle<float> area,
                                  bool vertical)
    {
        g.fillAll (splitterFill ());
        g.setColour (splitterGrip ());

        if (! vertical)
        {
            const float cx = area.getCentreX ();
            const float y1 = area.getY () + area.getHeight () * 0.30f;
            const float y2 = area.getY () + area.getHeight () * 0.70f;
            for (int i = -1; i <= 1; ++i)
                g.drawVerticalLine (cx + i * 3.0f, y1, y2);
        }
        else
        {
            const float cy = area.getCentreY ();
            const float x1 = area.getX () + area.getWidth () * 0.30f;
            const float x2 = area.getX () + area.getWidth () * 0.70f;
            for (int i = -1; i <= 1; ++i)
                g.drawHorizontalLine (cy + i * 3.0f, x1, x2);
        }
    }
}
