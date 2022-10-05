void createJoystickTables() {
// conversion tables to convert joystick angle (0to360 degrees) to Motor Left & Right Mix (-100to100 %)
// convention is joystick angle 0 degrees = straight ahead (North) and 90 degrees = to the right (East)
// also provides lookuptable for non-linear radius control (calculates %power from 0-100 radius)

//#include "joystickCals.h";

// Angle Lookup Table (Mix)

  // Generate LookupTables for L Mix
  float mixTableLTemp[14][2] = 
    {
      { 0                , motorForward_PowerLevels },
      { straightDwell , motorForward_PowerLevels },
      { 90 - spinZone , motorTurnFor_PowerLevels    },
      { 90 - spinDwell, motorSpin_PowerLevels    },
      { 90 + spinDwell, motorSpin_PowerLevels    },
      { 90 + spinZone , 0 },
      { 180 -straightDwell, - motorReverse_PowerLevels },
      { 180 +straightDwell, - motorReverse_PowerLevels },
      { 270 - spinZone, - motorTurnRev_PowerLevels },
      { 270 -spinDwell, - motorSpin_PowerLevels },
      { 270 +spinDwell, - motorSpin_PowerLevels },
      { 270 + spinZone, 0 },
      { 360 -straightDwell, motorForward_PowerLevels   },
      { 360              , motorForward_PowerLevels }
  };
  memcpy(mixTableL, mixTableLTemp, sizeof(mixTableLTemp));

  // Generate LookupTables for R Mix  
  float mixTableRTemp[14][2] = {
      { 0                , motorForward_PowerLevels },
      { straightDwell , motorForward_PowerLevels },
      { 90 - spinZone , 0    },
      { 90 - spinDwell, - motorSpin_PowerLevels    },
      { 90 + spinDwell, - motorSpin_PowerLevels    },
      { 90 + spinZone , - motorTurnRev_PowerLevels },
      { 180 -straightDwell, - motorReverse_PowerLevels },
      { 180 +straightDwell, - motorReverse_PowerLevels },
      { 270 - spinZone, 0 },
      { 270 -spinDwell, motorSpin_PowerLevels },
      { 270 +spinDwell, motorSpin_PowerLevels },
      { 270 + spinZone, motorTurnFor_PowerLevels },
      { 360 -straightDwell, motorForward_PowerLevels   },
      { 360              , motorForward_PowerLevels }
    
  };
  memcpy(mixTableR, mixTableRTemp, sizeof(mixTableRTemp));

// Radius Lookup Table (Scale)

  // Generate LookupTable for Scale
  float radTableTemp[6][2] = {
      { 0             , 0 },
      { Deadband   , 0 },
      { Deadband + .01 , 0 },
      { SlowRadius , SlowPower },
      { 1 -Endband , 1 },
      { 1             , 1 }
  };
  memcpy(radTable, radTableTemp, sizeof(radTableTemp));
  
}
