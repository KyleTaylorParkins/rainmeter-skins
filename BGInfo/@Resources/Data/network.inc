; LAN config WS1

[Variables]
NIC1="Intel(R) I210 Gigabit Network Connection #2"
NIC2="Intel(R) I210 Gigabit Network Connection"
NIC3="Intel(R) PRO/1000 PT Dual Port Server Adapter"
NIC4="Intel(R) PRO/1000 PT Dual Port Server Adapter #2"

[MeasureNicName1]
Measure=String
String=#NIC1#
RegExpSubstitute=1
Substitute="\(R\)":"","\(TM\)":"","\(tm\)":"","Gigabit Network Connection":""

[MeasureIPNic1]
Measure=Plugin
Plugin=SysInfo
SysInfoType=IP_ADDRESS
SysInfoData=#NIC1#

[MeasureNetInNic1]
Measure=NetIn
Interface=#NIC1#
UseBits:1

[MeasureNetOutNic1]
Measure=NetOut
Interface=#NIC1#
UseBits:1

[MeasureNicName2]
Measure=String
String=#NIC2#
RegExpSubstitute=1
Substitute="\(R\)":"","\(TM\)":"","\(tm\)":"","Gigabit Network Connection":""

[MeasureIPNic2]
Measure=Plugin
Plugin=SysInfo
SysInfoType=IP_ADDRESS
SysInfoData=#NIC2#

[MeasureNetInNic2]
Measure=NetIn
Interface=#NIC2#
UseBits:1

[MeasureNetOutNic2]
Measure=NetOut
Interface=#NIC2#
UseBits:1

[MeasureIPNic3]
Measure=Plugin
Plugin=SysInfo
SysInfoType=IP_ADDRESS
SysInfoData=#NIC3#

[MeasureIPNic4]
Measure=Plugin
Plugin=SysInfo
SysInfoType=IP_ADDRESS
SysInfoData=#NIC4#
