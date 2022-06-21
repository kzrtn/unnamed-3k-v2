# unnamed-3k-v2 keypad
 A simple 3 key mechanical hotswap keypad for osu! Uses an Atmega32u2 (also compatible with Atmega16u2). Created using Kicad and AutoCad/Coreldraw.
 
 ![keypad image](https://cdn.discordapp.com/attachments/733003518465540278/988595784138260540/image.png)
 ![another keypad image](https://cdn.discordapp.com/attachments/733003518465540278/988595784918384720/image2.png)
 
 ## IMPORTANT
 This uploaded version of the keypad is **slightly changed** from the prototype in the pictures above.
 
 **Changes:**
 - Removed in-key LEDs
 - Changed north facing switches to south facing
 - Switch pins were changed from B4, B6, B7 to B7, C7, C6
 - Removed unnecessary vias.

This means that what is put up here is **untested**. However if you've tried producing this and everything checks out (it should, changes were very minor) please send me an email at `jolene.tkk@gmail.com` or contact me somehow. I'll update this page and/or fix any issues raised.
 
 ## Features
 - Cherry MX hotswap
 - Uses QMK and has VIA (sort of)
 - 1000hz, chordsplits at 1ms
 - Acrylic sandwich
 - RGB underglow

**Notes regarding QMK and VIA:**

This is not pushed into QMK or VIA's repo. QMK source files are found in the firmware folder. To use VIA with the keypad, go to `settings tab in the VIA software > enable 'Show Design Tab > go to Design tab > Load Draft Definition > Upload the 'load_in_VIA.json' file from qmk-unnamed3kv2-source folder`. **You will have to do this each time you want to use VIA**.

## Settings and RGB modes
Upon plugging in, you will be booted into **Layer 0** where it outputs Z, X and C (play mode). To change RGB modes, hold down the first button (first button on the far left) while plugging in the keypad. It will boot into **Layer 1**.
### Layer 0
| First key  | Second key | Third key |
| ------------- | ------------- |------------- |
| Z | X  | C |
### Layer 1
| First key  | Second key | Third key |
| ------------- | ------------- |------------- |
| Change RGB Mode | Toggle RGB on/off | Go to Layer 2 |
### Layer 2
| First key  | Second key | Third key |
| ------------- | ------------- |------------- |
| Hue value + | Hue value - | Go to Layer 3 |
### Layer 3
| First key  | Second key | Third key |
| ------------- | ------------- |------------- |
| Sat value + | Sat value - | Go to Layer 4 |
### Layer 4
| First key  | Second key | Third key |
| ------------- | ------------- |------------- |
| Brightness value + | Brightness value - | Go to Layer 0 |

**RGB MODES**

- Breathing
- Rainbow mood
- Rainbow swirl
- Static

## Required parts
- PCB with components
- Laser cut acrylic
- 4 x M2 17mm hex stands
- 8 x M2 screws
- (optional) Rubber feet

## PCB assembly tips
![3D view PCB](https://cdn.discordapp.com/attachments/733003518465540278/988607382391251004/image4.png)
![PCB in Kicad](https://cdn.discordapp.com/attachments/733003518465540278/988607382714191892/image3.png)

The BOM and POS files in `PCB files/Gerber and JLCPCB files` are generated for easy ordering from [JLCPCB](https://jlcpcb.com/). For any parts that are unavailable, especially the crystal and/or the capacitors for the crystal, choose something else that's also 16Mhz with another capacitive load value that's available. Calculate the new values for the caps of the new crystal accordingly using this formula:
```
CL = ((CX1 x CX2) / (CX1 + CX2)) + Cstray

CL: The crystal load capacitance
CX1: The first capacitor
CX2: The second capacitor
Cstray: The stray capacitance in the oscillator circuit, which will normally be in the 2pF to 5pF range.

Assuming that CX1=CX2 then the equation becomes:

CL = ((CX1 x CX1) / (2 x CX1)) + Cstray

CL = (CX1 / 2) + Cstray

Rearranging the equation, we can find the external load capacitor value:

CX1 = 2(CL - Cstray)

For example, if the crystal load capacitance is 15pF, and assuming Cstray=2pF, then:

CX1 = CX2 = 2(15pF - 2pF) = 26pF
```

In the event that you would like to use an **atmega16u2** instead of atmega32u2, you can just do that, no PCB edits is required. But please read the firmware notes section of this readme to adjust the firmware accordingly.

| Part name  | Package type | Notes |
| ------------- | ------------- |------------- |
| Crystal  | SMD3225-4P  | 16MHz is REQUIRED |
| Capacitors  | 0805  |  |
| Resistors | 0805 | |
| Fuse | 1206 | [This](https://lcsc.com/product-detail/Resettable-Fuses_TECHFUSE-nSMD025-24V_C70069.html) is the one I used. Otherwise, ensure your fuse is rated 500mA |
| Kailh hotswap sockets |  | [They're](https://lcsc.com/product-detail/Mechanical-Keyboard-Shaft_Kailh-CPG151101S11_C2803348.html) now available on JLCPCB and LCSC |
| WS2812B (LEDs) |  | Easily found on [JLCPCB](https://lcsc.com/product-detail/Light-Emitting-Diodes-LED_Worldsemi-WS2812B-B-W_C2761795.html) and other websites |
| Tactile switch |  | Easily found on [JLCPCB](https://lcsc.com/product-detail/Tactile-Switches_ALPSALPINE-SKQGABE010_C115351.html) and other websites |

## Acrylic case notes
![Case thickness](https://cdn.discordapp.com/attachments/733003518465540278/988611059038421072/canvas1.png)

There are 3 different file formats here. AutoCAD, Coreldraw and PDF.

AutoCAD files are in the 'might be broken and wrong thickness' folder. When I tried exporting the AutoCAD files to .pdf, it would export in the wrong size. I'm not sure if the drawings themselves in the AutoCad files are wrong. They are also outdated, layers are not labelled with the correct thickness, if you use the AutoCAD files, please check the dimensions and the correct the thickness labels to the image shown above (image edited from `new laser cut 16.0.pdf`. The other issue with the AutoCAD file is that the USB cut out size is too big, it will not cover the underside of the USB port properly, if you plan to use AutoCAD, please edit this accordingly.

Coreldraw files are available in latest and 16.0 versions. I'm not sure if both of them are properly up to date (my Coreldraw trial has expired). Please check if they meet the requirements I pointed out in the paragraph above. I'd stick with the `new laser cut 16.0.pdf` file, because that's the last file I used.

**Additional note:** The holes for the hex stands can be quite tight in the `new laser cut 16.0.pdf` file. If they're too tight for your hex stands, enlarge them a little.

For best light diffusion effects, the last layer should use a matte/frosted piece of acrylic. The top of layer can also be matte/frosted for good light diffusion on the top.

## Firmware notes
To flash the firmware, use [QMK toolbox](https://github.com/qmk/qmk_toolbox). Load one of the `.hex` files provided in the `firmware/qmk hex files` folder. `unnamed3kv2_default.hex` does not have (manual) VIA support. `unnamed3kv2_via.hex` has (manual) VIA support. Make sure that the MCU is set to `atmega32u2`, if you are using `atmega16u2`, change it to that instead.

![QMK toolbox](https://cdn.discordapp.com/attachments/733003518465540278/988618139677913088/Untitled-6_copy.png)

For tinkering with the firmware source, all the files are in `firmware/unnamed3kv2source`. To compile, use QMK MSYS.

**In the case where you are using an atmega16u2**, you'll have to edit the `rules.mk` file in `firmware/unnamed3kv2source`. Change `MCU = atmega32u2` to `MCU = atmega16u2` and recompile the firmware with [QMK MSYS](https://msys.qmk.fm/).

## Printing your own images for decoration
Reuse the same `new laser cut 16.0.pdf` file. Load it into an image editor like Photoshop and put it over whatever image you'd like to use and export it as an image or .pdf then print it out on a piece of paper. **Remember to check fill image to paper size** or similar setting your printer has. Make sure there is no margins so the printed image is the correct size.

**[Print settings example](https://cdn.discordapp.com/attachments/733003518465540278/988617787540930600/print_sizing.png)**

## Learning PCB design with this project
This makes a decent reference, but I don't advise using the same libraries as me because they're outdated and trigger clearance errors in Kicad. Please use [ebalster's keyboard parts library](https://github.com/ebastler/marbastlib) for parts instead.

**Useful resources**
- [My PCB design notes](https://docs.google.com/document/d/1xsjb1sf3pxFw8bXC4gNhWsFhWNOthMoyz6RiJc1UtVI/edit)
- [Best PCB design practices](https://gist.github.com/Sleepdealr/ab05f5edb82eae9e0393f4d63da55adf)
