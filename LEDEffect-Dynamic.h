/* Kaleidoscope-LEDEffect-SolidColor - Solid color LED effects for Kaleidoscope.
 * Copyright (C) 2017  Keyboard.io, Inc.
 *
 * This program is free software: you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free Software
 * Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE. See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program. If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "Kaleidoscope-LEDControl.h"
#include <Kaleidoscope-LEDEffects.h>

namespace kaleidoscope {
namespace plugin {
class LEDDynamic : public Plugin,
  public LEDModeInterface {
 public:

  LEDDynamic(void) {}

  uint8_t update_delay() {
    return update_delay_;
  }
  void update_delay(uint8_t delay) {
    update_delay_ = delay;
  }

  void set_left_color(cRGB col) {
    left_color_ = col;
  }

  void set_bottom_color(cRGB col) {
    bottom_color_ = col;
  }

  void set_right_color(cRGB col) {
    right_color_ = col;
  }

  // This class' instance has dynamic lifetime
  //
  class TransientLEDMode : public LEDMode {
   public:

    // Please note that storing the parent ptr is only required
    // for those LED modes that require access to
    // members of their parent class. Most LED modes can do without.
    //
    TransientLEDMode(const LEDDynamic *parent)
      : parent_(parent), last_update_(Kaleidoscope.millisAtCycleStart()) {}

   protected:
    virtual void onActivate(void) final;
    virtual void update() final;

   private:

    const LEDDynamic *parent_;
    uint16_t last_update_;
  };

 private:

  uint8_t r_, g_, b_;
  uint8_t update_delay_ = 150;
  cRGB left_color_ = CRGB(127, 0, 0);
  cRGB bottom_color_ = CRGB(0, 0, 127);
  cRGB right_color_ = CRGB(0, 127, 0);
};
}
}

extern kaleidoscope::plugin::LEDDynamic LEDDynamic;
