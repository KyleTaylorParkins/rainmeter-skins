; #### OS  ####
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

; #### Network ####
;[MeasureIP]
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

[MeasureNIC1]
Measure=Plugin
Plugin=SysInfo
SysInfoType=ADAPTER_DESCRIPTION
SysInfoData=0
RegExpSubstitute=1
Substitute="(R)":"", " (3)":"", ".*VMware.*":"-1"

[MeasureNIC2]
Measure=Plugin
Plugin=SysInfo
SysInfoType=ADAPTER_DESCRIPTION
SysInfoData=1
RegExpSubstitute=1
Substitute="(R)":"", " (3)":"", ".*VMware.*":"-1"

[MeasureUpTime]
Measure=UPTIME
Format="%4!i!d %3!i!h %2!i!m"
UpdateDivider=60

; #### Hardware ####

[MeasureCPU]
Measure=CPU

[MeasureCPUName]
Measure=Registry
RegHKey=HKEY_LOCAL_MACHINE
RegKey=HARDWARE\DESCRIPTION\System\CentralProcessor\0
RegValue=ProcessorNameString
UpdateDivider=28800
Substitute="CPU":"", "(R)":"", "(TM)":"", "(tm)":"", "       ":""

[MeasureCPUSpeed1]
Measure=Plugin
Plugin=Plugins\PowerPlugin.dll
PowerState=MHz

[MeasureRAM]
Measure=PhysicalMemory

[MeasureRAMTotal]
Measure=PhysicalMemory
Total=1

[MeasurePower]
Measure=Plugin
Plugin=PlugIns\PowerPlugin.dll
PowerState=ACLINE

[MeasureBattery]
Measure=Plugin
Plugin=Plugins\PowerPlugin.dll
PowerState=PERCENT
