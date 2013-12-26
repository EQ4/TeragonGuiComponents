/*
Copyright (c) 2013 Teragon Audio. All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

- Redistributions of source code must retain the above copyright notice,
  this list of conditions and the following disclaimer.
- Redistributions in binary form must reproduce the above copyright notice,
  this list of conditions and the following disclaimer in the documentation
  and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef __TOGGLEBUTTON_H_CCE55A62__
#define __TOGGLEBUTTON_H_CCE55A62__

#include "ThinButton.h"

namespace teragon {

/**
* A toggle button widget which does not show a current state. This is mostly
* useful for triggering actions, such as save, open, etc. Although this
* component does not require a given parameter type, it is most useful when
* bound to a VoidParameter, which can act as a basic message passing system
* between the GUI and core of an application.
*/
class ToggleButton : public ThinButton {
public:
    ToggleButton(ConcurrentParameterSet &parameters, const ParameterString &name,
                 const ResourceCache *resources) :
    ThinButton(parameters, name, resources, "toggle_button") {
        setClickingTogglesState(false);
    }

    virtual ~ToggleButton() {}

    const Image getImageForButtonState() {
        return isDown() ? getDownImage() : getNormalImage();
    }
};

} // namespace teragon

#endif  // __TOGGLEBUTTON_H_CCE55A62__
