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

#include "Kaleidoscope-LEDEffect-Dynamic.h"

namespace kaleidoscope {
namespace plugin {

void LEDDynamic::TransientLEDMode::onActivate(void) {
  ::LEDControl.set_all_leds_to(parent_->left_color_);

  for (byte pos = 0; pos <= 26; pos++) {
    ::LEDControl.setCrgbAt(pos, parent_->left_color_);
  }

  for (byte pos = 27; pos <= 36; pos++) {
    ::LEDControl.setCrgbAt(pos, parent_->bottom_color_);
  }

  for (byte pos = 37; pos <= 63; pos++) {
    ::LEDControl.setCrgbAt(pos, parent_->right_color_);
  }
}

void LEDDynamic::TransientLEDMode::update() {
  if (!Kaleidoscope.hasTimeExpired(last_update_, parent_->update_delay_)) {
    return;
  }
  last_update_ += parent_->update_delay_;

  for (byte pos = 0; pos <= 26; pos++) {
    ::LEDControl.setCrgbAt(pos, parent_->left_color_);
  }

  for (byte pos = 27; pos <= 36; pos++) {
    ::LEDControl.setCrgbAt(pos, parent_->bottom_color_);
  }

  for (byte pos = 37; pos <= 63; pos++) {
    ::LEDControl.setCrgbAt(pos, parent_->right_color_);
  }
}
}

}

kaleidoscope::plugin::LEDDynamic LEDDynamic;
