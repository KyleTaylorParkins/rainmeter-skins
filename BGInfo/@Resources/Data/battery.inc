; ------------------------------------------------------------------------
; MEASURES
; ------------------------------------------------------------------------

[MeasureBatteryACLine]
; Returns the status of the AC Line (0 for battery or 1 when plugged in).
; Controls the charging vs. discharging functionality.
Measure=Plugin
Plugin=PowerPlugin
PowerState=ACLine
IfEqualValue=1
IfEqualAction=[!HideMeterGroup Discharging][!HideMeterGroup TimeRemaining][!HideMeter Remaining][!ShowMeter ChargingStatus][!HideMeter ChargedStatus][!ShowMeterGroup BatteryCharging][!HideMeter Calculating]
IfBelowValue=1
IfBelowAction=[!ShowMeterGroup Discharging][!HideMeter ChargingStatus][!HideMeter ChargedStatus][!HideMeterGroup BatteryCharging][!ShowMeter Calculating]

[MeasureBatteryPercent]
; Returns the percentage of charge remaining in the battery.
; Controls the visibility of the "Charged" text.
; Controls the anti-aliasing pixels of the charging battery icon.
Measure=Plugin
Plugin=PowerPlugin
PowerState=Percent
OnChangeAction=[!UpdateMeasure MeasureBatteryBarCharging][!UpdateMeter MeterBatteryBarDischarging][!UpdateMeter MeterBatteryBarCharging][!UpdateMeter MeterBatteryPercent][!UpdateMeter Remaining]
IfCondition=(MeasureBatteryPercent=100) && (MeasureBatteryACLine=1)
IfTrueAction=[!HideMeterGroup Discharging][!HideMeterGroup TimeRemaining][!HideMeter ChargingStatus][!ShowMeter ChargedStatus][!ShowMeterGroup BatteryCharging][!ShowMeterGroup BatteryChargingAntiAlias]
IfCondition2=(MeasureBatteryPercent<10) && (MeasureBatteryACLine=1)
IfTrueAction2=[!HideMeterGroup BatteryChargingAntiAlias]
IfCondition3=(MeasureBatteryPercent>=10) && (MeasureBatteryACLine=1)
IfTrueAction3=[!ShowMeterGroup BatteryChargingAntiAlias]
IfConditionMode=1

[MeasureBatteryHours]
; Returns the estimated number of hours the battery will last.
; Controls the plurality of the hour measurement.
; Controls the visibility of the hour measurement.
Measure=Plugin
Plugin=PowerPlugin
PowerState=Lifetime
Substitute="Unknown":"-1","":"-1"
Format=%#H
OnChangeAction=[!UpdateMeter MeterBatteryHours]
IfMatch=^1$
IfMatchAction=!SetVariable hrS ""
IfNotMatchAction=!SetVariable hrS "s"
IfMatch2=^0$
IfMatchAction2=[!HideMeter MeterBatteryHours]
IfCondition=([MeasureBatteryHours] > 0)
IfTrueAction=[!ShowMeter MeterBatteryHours][!ShowMeter Remaining][!HideMeter Calculating]]
IfCondition2=([MeasureBatteryHours] < 0)
IfTrueAction2=[!HideMeter MeterBatteryHours][!HideMeter Remaining]
DynamicVariables=1
IfConditionMode=1

[MeasureBatteryMinutes]
; Returns the estimated number of minutes the battery will last.
; Controls the plurality of the minute measurement.
; Controls the visibility of the minute measurement.
Measure=Plugin
Plugin=PowerPlugin
PowerState=Lifetime
Substitute="Unknown":"-1","":"-1"
Format=%#M
OnChangeAction=[!UpdateMeter MeterBatteryMinutes]
IfMatch=^1$
IfMatchAction=!SetVariable minS ""
IfNotMatchAction=!SetVariable minS "s"
IfMatch2=^0$
IfMatchAction2=[!HideMeter MeterBatteryMinutes]
IfCondition=([MeasureBatteryMinutes] > 0)
IfTrueAction=[!ShowMeter MeterBatteryMinutes][!ShowMeter Remaining][!HideMeter Calculating]
IfCondition2=([MeasureBatteryMinutes] < 0)
IfTrueAction2=[!HideMeter MeterBatteryMinutes][!HideMeter Remaining]
DynamicVariables=1
IfConditionMode=1

[MeasureBatteryBarCharging]
Measure=Calc
Formula=((MeasureBatteryPercent/100)*#BatteryBarWidth#)
OnChangeAction=[!UpdateMeter MeterBatteryBarCharging1][!UpdateMeter MeterBatteryBarCharging2][!UpdateMeter MeterBatteryBarCharging3][!UpdateMeter MeterBatteryBarCharging4]
UpdateDivider=-1
