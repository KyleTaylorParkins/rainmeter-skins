; OS
[MeasureOSVersion]
Measure=Plugin
Plugin=SysInfo
SysInfoType=OS_VERSION
UpdateDivider=-1

[MeasureOSVersionFull]
Measure=Registry
RegHKey=HKEY_LOCAL_MACHINE
RegKey=SOFTWARE\Microsoft\Windows NT\CurrentVersion\
RegValue=ProductName
UpdateDivider=28800

[MeasureUser]
Measure=Plugin
Plugin=SysInfo
SysInfoType=USER_NAME

[MeasureHost]
Measure=Plugin
Plugin=SysInfo
SysInfoType=HOST_NAME

[MeasureDomain]
Measure=Plugin
Plugin=SysInfo
SysInfoType=DOMAIN_NAME

; Common network
[MeasureWANIP]
Measure=Plugin
Plugin=WebParser.dll
Url=http://checkip.dyndns.org
UpdateRate=14400
RegExp="(?siU)Address: (.*)</body>"
StringIndex=1
Substitute="":"N/A"

[MeasureSSID]
Measure=Plugin
Plugin=Plugins\WifiStatus.dll
WifiInfoType=SSID
WifiIntfID=0
WifiListStyle=0

[MeasureUpTime]
Measure=UPTIME
Format="%4!i!d %3!i!h %2!i!m"
UpdateDivider=60

; Hardware

[MeasureCPU]
Measure=CPU

[MeasureCore1]
Measure=CPU
Processor=1

[MeasureCore2]
Measure=CPU
Processor=2

[MeasureCore3]
Measure=CPU
Processor=3

[MeasureCore4]
Measure=CPU
Processor=4

[MeasureCore5]
Measure=CPU
Processor=5

[MeasureCore6]
Measure=CPU
Processor=6

[MeasureCore7]
Measure=CPU
Processor=7

[MeasureCore8]
Measure=CPU
Processor=8

[MeasureCore9]
Measure=CPU
Processor=9

[MeasureCore10]
Measure=CPU
Processor=10

[MeasureCPUName]
Measure=Registry
RegHKey=HKEY_LOCAL_MACHINE
RegKey=HARDWARE\DESCRIPTION\System\CentralProcessor\0
RegValue=ProcessorNameString
RegExpSubstitute=1
Substitute="\(R\)":"","\(TM\)":"","\(tm\)":"","CPU ":"","@.*":"","\s$":""
UpdateDivider=-1

[MeasureGPUName]
Measure=Plugin
Plugin=RunCommand
Parameter=wmic path win32_VideoController get Name
State=Hide
OutputType=ANSI
RegExpSubstitute=1
Substitute="Name.*#CRLF#":"","#CRLF#":"","\(R\)":"","\(TM\)":"","\(tm\)":""
UpdateDivider=-1

[MeasureCPUSpeed]
Measure=Plugin
Plugin=Plugins\PowerPlugin.dll
PowerState=MHz

[MeasureRAM]
Measure=PhysicalMemory

[MeasureRAMFree]
Measure=PhysicalMemory
InvertMeasure=1

[MeasureRAMTotal]
Measure=PhysicalMemory
Total=1

[MeasureGPUUtilRaw]
Measure=Plugin
Plugin=UsageMonitor
Alias=GPU
Index=0

[MeasureGPUUtil]
Measure=Calc
Formula=MeasureGPUUtilRaw

; [MeasureVRAMUtilRaw]
; Measure=Plugin
; Plugin=UsageMonitor
; Alias=VRAM
; Index=0

; [MeasureVRAMUtil]
; Measure=Calc
; Formula=MeasureVRAMUtilRaw

[MeasurePower]
Measure=Plugin
Plugin=PlugIns\PowerPlugin.dll
PowerState=ACLINE

[MeasureBattery]
Measure=Plugin
Plugin=Plugins\PowerPlugin.dll
PowerState=PERCENT

[MeasureBatteryMinutes]
Measure=Plugin
Plugin=PowerPlugin
PowerState=Lifetime
Substitute="Unknown":"-1","":"-1"
Format=%#M