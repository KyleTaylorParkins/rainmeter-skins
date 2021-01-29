[Variables]
;Fonts
FontSegoe=Segoe UI
FontSegoeLight=Segoe UI Light
FontSegoeBold=Segoe UI Bold

;Colors
Background=255,255,255,1
Clear=255,255,255,0
TileColor=89,89,89,150
GraphBackColor=255,255,255,25
;Font Colors
DefaultFontColor=255, 255, 255
SubtitleColor=192,192,192

;Sizes
; Scalefactor determines how much the skins need to be scaled, to provide compatibility with Windows DPI settings.
; Set 1.25 for 125% scaling, 1.5 for 150% etc.
; Set the preffered basis size in Small, and the calculations will do the rest.
; Do NOT change other values manual as it will screw up the skins and layouts!
Scalefactor=1
Small=(60*#Scalefactor#)
Normal=((#Small#*2) + (#Offset#*2))
Large=((#Normal#*2) + (#Offset#*2))

;Styles
;For all text on the bottom or top of the skins
[styleTitle]
StringAlign=Left
FontSize=(9*#Scalefactor#)
FontColor=#DefaultFontColor#
FontFace=#FontSegoe#
AntiAlias=1
ClipString=1

;For all text with changing data in the skin

[styleTextTitle]
StringAlign=Left
FontSize=(19*#Scalefactor#)
FontColor=#DefaultFontColor#
FontFace=#FontSegoe#
StringStyle=Bold
AntiAlias=1
ClipString=1

[styleText]
StringAlign=Left
FontSize=(11*#Scalefactor#)
FontColor=#SubtitleColor#
FontFace=#Font#
AntiAlias=1
ClipString=1

[styleTextBold]
StringAlign=Left
FontSize=(12*#Scalefactor#)
FontColor=#DefaultFontColor#
FontFace=#FontSegoe#
StringStyle=Bold
AntiAlias=1
ClipString=1

[styleBar]
BarColor=#DefaultFontColor#
BarOrientation=HORIZONTAL
SolidColor=#TransparentFont#

[styleGraph]
LineCount=1
LineColor=#DefaultFontColor#
SolidColor=#GraphBackColor#
AntiAlias=1
GraphStart=left
