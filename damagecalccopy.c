#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float Attack;
float Defense;
float Level;
float Power;

float TypeValues[] = {0.4, 0.5, 1, 2, 2.25};

float CurrentAtkMod;
float CurrentDefMod;

float DamageRolls[] = {85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100};

float Type = 1;
float Weather = 1;
float Critical = 1;
float STAB = 1;
float BurnFrostbite = 1;
float Drowsy = 1;
float FixatedOffense = 1;
float FixatedDefense = 1;
float Primed = 1;

float BaseDamage;
float MultipliedDamage;
float FinalDamageValues[16];

//ask the user to input the values required for damage calculation.
//functions for Attack, Defense, Level and Power require to manually type the value.
//the remaining functions verify whether or not an additional modifier needs to be applied or not.

float getAttack(float Attack) {
    printf("\nInsert the Attack stat: ");
    scanf("%f", &Attack);
    return Attack;
}

float getDefense(float Defense) {
    printf("\nInsert the Defense stat: ");
    scanf("%f", &Defense);
    return Defense;
}

float getLevel(float Level) {
    printf("\nInsert the level: ");
    scanf("%f", &Level);
    return Level;
}

float getBasePower(float Power){
    printf("\nInsert the base power: ");
    scanf("%f", &Power);
    return Power;
}

float getAtkMod(float CurrentAtkMod) {
    int CurrentAtkCheck;
    printf("\nEnter correct value for Atk modifier (1 if increased, 2 if neutral, 3 if decreased): ");
    scanf("%d", &CurrentAtkCheck);

    switch(CurrentAtkCheck) {
        case 1:
        CurrentAtkMod = 1.5;
        break;
        case 2:
        CurrentAtkMod = 1;
        break;
        case 3:
        CurrentAtkMod = 0.66;
        break;
        default:
        printf("\nInvalid input.\n\n");
        exit(EXIT_FAILURE);
    }
    return CurrentAtkMod;
}

float getDefMod(float CurrentDefMod) {
    int CurrentDefCheck;
    printf("\nEnter correct value for Def modifier (1 if increased, 2 if neutral, 3 if decreased): ");
    scanf("%d", &CurrentDefCheck);

    switch(CurrentDefCheck) {
        case 1:
        CurrentDefMod = 1.5;
        break;
        case 2:
        CurrentDefMod = 1;
        break;
        case 3:
        CurrentDefMod = 0.66;
        break;
        default:
        printf("\nInvalid input.\n\n");
        exit(EXIT_FAILURE);
    }

    return CurrentDefMod;
}

float getType(float Type){

    int CurrentTypeCheck;
    printf("\nEnter the correct value for type effectiveness (1 for double resist, 2 for resist, 3 for weak, 4 for double weak, 5 for neutral): ");
    scanf("%d", &CurrentTypeCheck);

    switch(CurrentTypeCheck) {
        case 1:
        Type = 0.4;
        break;
        case 2:
        Type = 0.5;
        break;
        case 3:
        Type = 2;
        break;
        case 4:
        Type = 2.25;
        break;
        case 5:
        break;
        default:
        printf("\nInvalid input.\n\n");
        exit(EXIT_FAILURE);
    }

    return Type;
}

float getWeather(float Weather) {
    int WeatherCheck;
    printf("\nEnter 1 if you're using a Fire-type move in the rain, 0 otherwise: ");
    scanf("%d", &WeatherCheck);
    switch(WeatherCheck) {
        case 1:
        Weather = 0.75;
        break;
        case 0:
        break;
        default:
        printf("\nInvalid input.\n\n");
        exit(EXIT_FAILURE);
    }
    return Weather;
}

float getCritical(float Critical) {
    int CriticalCheck;
    printf("\nEnter 1 if the move is a critical hit, 0 otherwise: ");
    scanf("%d", &CriticalCheck);
    switch(CriticalCheck) {
        case 1:
        Critical = 1.5;
        break;
        case 0:
        break;
        default:
        printf("\nInvalid input.\n\n");
        exit(EXIT_FAILURE);
    }
    return Critical;
}

float getSTAB(float STAB) {
    int STABCheck;
    printf("\nEnter 1 if the move is STAB, 0 otherwise: ");
    scanf("%d", &STABCheck);
    switch(STABCheck) {
        case 1:
        STAB = 1.5;
        break;
        case 0:
        break;
        default:
        printf("\nInvalid input.\n\n");
        exit(EXIT_FAILURE);
    }
    return STAB;
}

float getBurnFrostbite(float BurnFrostbite) {
    int BurnFrostbiteCheck;
    printf("\nEnter 1 if the attacker is affected by burn or frostbite, 0 otherwise: ");
    scanf("%d", & BurnFrostbiteCheck);
    switch(BurnFrostbiteCheck) {
        case 1:
        BurnFrostbite = 1.5;
        break;
        case 0:
        break;
        default:
        printf("\nInvalid input.\n\n");
        exit(EXIT_FAILURE);
    }
    return BurnFrostbite;
}

float getDrowsy (float Drowsy) {
    int DrowsyCheck;
    printf("\nEnter 1 if the target is drowsy, 0 otherwise: ");
    scanf("%d", &DrowsyCheck);
    switch(DrowsyCheck) {
        case 1:
        Drowsy = 1.33;
        break;
        case 0:
        break;
        default:
        printf("\nInvalid input.\n\n");
        exit(EXIT_FAILURE);
    }
    return Drowsy;
}

float getFixatedOffense(float FixatedOffense) {
    int FixatedOffenseCheck;
    printf("\nEnter 1 if the attacker is fixated, 0 otherwise: ");
    scanf("%d", &FixatedOffenseCheck);
    switch(FixatedOffenseCheck) {
        case 1:
        FixatedOffense = 1.5;
        break;
        case 0:
        break;
        default:
        printf("\nInvalid input.\n\n");
        exit(EXIT_FAILURE);
    }
    return FixatedOffense;
}

float getFixatedDefense(float FixatedDefense) {
    int FixatedDefenseCheck;
    printf("\nEnter 1 if the target is fixated, 0 otherwise: ");
    scanf("%d", &FixatedDefenseCheck);
    switch(FixatedDefenseCheck) {
        case 1:
        FixatedDefense = 1.33;
        break;
        case 0:
        break;
        default:
        printf("\nInvalid input.\n\n");
        exit(EXIT_FAILURE);
    }
    return FixatedDefense;
}

float getPrimed(float Primed) {
    int PrimedCheck;
    printf("\nEnter 1 if the attacker is primed, 0 otherwise: ");
    scanf("%d", &PrimedCheck);
    switch(PrimedCheck) {
        case 1:
        Primed = 1.5;
        break;
        case 0:
        break;
        default:
        printf("\nInvalid input.\n\n");
        exit(EXIT_FAILURE);
    }
    return Primed;
}

int main(void) {

  Attack = getAttack(Attack);
  Defense = getDefense(Defense);
  Level = getLevel(Level);
  Power = getBasePower(Power);
  CurrentAtkMod = getAtkMod(CurrentAtkMod);
  CurrentDefMod = getDefMod(CurrentDefMod);
  Type = getType(Type);
  Weather = getWeather(Weather);
  Critical = getCritical(Critical);
  STAB = getSTAB(STAB);
  BurnFrostbite = getBurnFrostbite(BurnFrostbite);
  Drowsy = getDrowsy(Drowsy);
  FixatedOffense = getFixatedOffense(FixatedOffense);
  FixatedDefense = getFixatedDefense(FixatedDefense);
  Primed = getPrimed(Primed);
    
  //damage calculation formula: a base damage is determined with stats alone, and it's then multiplied by all the factors (defaulting to 1 if all inputs provided are negative)
  float Damage1;
  float Damage2;
  float Damage3;
  float AuxiliaryFactor1;
  float Damage4;
  float Damage5;
  float AuxiliaryFactor2;
  float Damage6;
  float Damage7;
  float Damage8;
  float Damage9;
  float Damage10;
  float Damage11;
  float Damage12;
  float Damage13;
  float Damage14;
  float Damage15;

  Damage1 = 15 * Level;
  Damage2 = 100 + Attack + Damage1;
  AuxiliaryFactor1 = Defense + 50;
  Damage3 = Damage2 * Power;
  Damage4 = Damage3 / AuxiliaryFactor1;
  Damage5 = Damage4 / 5;

  //add multipliers
  AuxiliaryFactor2 = CurrentAtkMod * CurrentDefMod;
  Damage6 = Damage5 * AuxiliaryFactor2;
  Damage7 = Damage6 * Type;
  Damage8 = Damage7 * Weather;
  Damage9 = Damage8 * Critical;
  Damage10 = Damage9 * STAB;
  Damage11 = Damage10 * BurnFrostbite;
  Damage12 = Damage11 * Drowsy;
  Damage13 = Damage12 * FixatedOffense;
  Damage14 = Damage13 * FixatedDefense;
  Damage15 = Damage14 * Primed;
  MultipliedDamage = Damage15;

    //determine the 16 different damage rolls
    for(int i = 0; i < 16; i++) {
        FinalDamageValues[i] = MultipliedDamage * (DamageRolls[i]/100);
    }
    //the final result can't be 0: if the final result is 0 after all the calculations, it gets increased to 1
    for (int j = 0; j < 16; j++) {
        if (fabs(FinalDamageValues[j]) < 0.0001) {
            FinalDamageValues[j] = 1;
        }
    }
    //print all the possible damage rolls
    for(int k = 0; k < 16; k++) {
        printf("\nDamage roll %d: %0.0f", k+1, FinalDamageValues[k]);
    }
  
  return 0;
}