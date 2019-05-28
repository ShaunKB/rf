# **RFNT** / RumbleFighter Nanmu Tool

Very simplistic tool for RumbleFighter to for infinite Nanmu.

## Use

Simply build the project and inject the library into the RumbleFighter client. When the client window is created, the library will initialize itself.

* Use the F1 key to reset your Nanmu counter. If you don't have Nanmu yet, this tool will enable it for you. A bypass is **not** required as we're flipping bytes back and forth.
* The F2 key will suspend you in air if you get knocked off a map or accidently fall off. Pressing the key again will resume the client's regular physics.
* To crash a room, use the F3 key. You must be in-game, press the key right before another player hits you and everyone but yourself will have their client crash.


## How it works

The RumbleFighter client has a realtime thread with a loop that checks your character's state. Nanmu locks are client sided as opposed to server sided, so simply modifying the register responsible will set your counter back to 0.

## Disclaimer

This project was created for eductional purposes only. I have not, and will not monetize this code for any personal gains.

---

Copyright (c) 2019 John Nolette Licensed under the MIT license.
