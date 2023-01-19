#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void temperature(int x, char* n, char* m);
void temp_generic(int x, char* n);
void distance(int x, char* n, char* m);
void dist_generic(int x, char* n);
void mass(int x, char* n, char* m);
void mass_generic(int x, char* n);

char* mass_units[11] = {"Pounds", "Pound", "Lbs", "Ounces", "Ounce", "Oz", "Gram", "Grams", "Kilogram", "Kilograms", "Kg"};
char* temp_units[6] = {"Celsius", "C", "Fahrenheit", "F", "Kelvin","K"};
char* dist_units[11] = {"Kilometers", "Kilometer", "Km", "Meters", "Meter", "Miles", "Mile", "Yards", "Yard", "Feet", "Foot"};


int main(int argc, char* argv[])
{
    printf("\n");

    int units = 0;
    int valid2 = 0;
    char* all_units[27] = {"Pounds", "Lbs", "Ounces", "Ounce", "Oz", "Gram", "Grams", "Kilogram", "Kilograms", "Kg", "Celsius", "C", "Fahrenheit", "F", "Kelvin","K", "Kilometers", "Kilometer", "Km", "Meters", "Meter", "Miles", "Mile", "Yards", "Yard", "Feet", "Foot"};
    char* j = argv[1];

    if (argc == 3 || argc == 4)
    {
        char* z = argv[2];
        char upper = toupper(z[0]);
        z[0] = upper;

        if (j[0] == '-')
        {
            printf("Error:\nInteger must be non-negative.\n\n");
            return 0;
        }

        for (int i = 0; i < 6; i++)
        {
            if (strcmp(z, temp_units[i]) == 0)
            {
                valid2++;
                units = 1;
                break;
            }
        }
        for (int i = 0; i < 11; i++)
        {
            if (strcmp(z, dist_units[i]) == 0)
            {
                valid2++;
                units = 2;
                break;
            }
        }
        for (int i = 0; i < 11; i++)
        {
            if (strcmp(z, mass_units[i]) == 0)
            {
                valid2++;
                units = 3;
                break;
            }
        }
        if (valid2 == 0)
        {
            printf("Error:\nMust enter your desired units on the command line. Output changes based on format of input.\n\n\"25 unit unit2\" for specific conversions from the first unit to the second.\n\"25 unit\" for general conversions for the amount of unit specified.\n\"unit unit2\" for specific conversions of value 1.\n\"unit\" for basic conversions of 1 of the specified starting unit.\n\nExamples:\n\"25 Celsius Fahrenheit\" returns \"25.00°C ---> 77.00°F\"\n\"25 Celsius\" returns \"25.00°C ---> 77.00°F || 298.15K\"\n\"Celsius Fahrenheit\" returns \"1.00°C ---> 33.80°F\"\n\"Celsius\" returns \"1.00°C ---> 33.80°F || 274.15K\"\n\nFor a list of all accepted units and variations, type \"Units\" in the command line prompt.\n");
            return 0;
        }
    }
    if (argc == 2)
    {
        if(strcmp(argv[1], "Units") == 0 || strcmp(argv[1], "units") == 0 || strcmp(argv[1], "Unit") == 0 || strcmp(argv[1], "unit") == 0 )
        {
            for (int i = 0; i < 27; i++)
            {
                printf("%s || ", all_units[i]);
                if (i == 13)
                {
                    printf("\n");
                }
            }
            printf("\n\n");
            return 0;
        }
        else
        {
            char* z = argv[1];
            char upper = toupper(z[0]);
            z[0] = upper;

            for (int i = 0; i < 6; i++)
            {
                if (strcmp(z, temp_units[i]) == 0)
                {
                    valid2++;
                    units = 1;
                    break;
                }
            }
            for (int i = 0; i < 11; i++)
            {
                if (strcmp(z, dist_units[i]) == 0)
                {
                    valid2++;
                    units = 2;
                    break;
                }
            }
            for (int i = 0; i < 11; i++)
            {
                if (strcmp(z, mass_units[i]) == 0)
                {
                    valid2++;
                    units = 3;
                    break;
                }
            }
        }
        if (valid2 == 0)
        {
            printf("Error:\nMust enter your desired units on the command line. Output changes based on format of input.\n\n\"25 unit unit2\" for specific conversions from the first unit to the second.\n\"25 unit\" for general conversions for the amount of unit specified.\n\"unit unit2\" for specific conversions of value 1.\n\"unit\" for basic conversions of 1 of the specified starting unit.\n\nExamples:\n\"25 Celsius Fahrenheit\" returns \"25.00°C ---> 77.00°F\"\n\"25 Celsius\" returns \"25.00°C ---> 77.00°F || 298.15K\"\n\"Celsius Fahrenheit\" returns \"1.00°C ---> 33.80°F\"\n\"Celsius\" returns \"1.00°C ---> 33.80°F || 274.15K\"\n\nFor a list of all accepted units and variations, type \"Units\" in the command line prompt.\n");
            return 0;
        }
    }

    // Switch statment to determine the units being used and swap accordingly to the necessary function

    switch(argc) {
        case 2:
            switch(units) {
                case 1:
                    temp_generic(1, argv[1]);
                    break;
                case 2:
                    dist_generic(1, argv[1]);
                    break;
                case 3:
                    mass_generic(1, argv[1]);
                    break;
            }
            break;
        case 3:
            switch(units) {
                case 1:
                    if (!(isdigit(j[0])))
                    {
                        temperature(1, argv[1], argv[2]);
                    }
                    else
                    {
                        temp_generic(atoi(argv[1]), argv[2]);
                    }
                    break;
                case 2:
                    if (!(isdigit(j[0])))
                    {
                        distance(1, argv[1], argv[2]);
                    }
                    else
                    {
                        dist_generic(atoi(argv[1]), argv[2]);
                    }
                    break;
                case 3:
                    if (!(isdigit(j[0])))
                    {
                        mass(1, argv[1], argv[2]);
                    }
                    else
                    {
                        mass_generic(atoi(argv[1]), argv[2]);
                    }
                    break;
            }
            break;
        case 4:
            switch(units) {
                case 1:
                    temperature(atoi(argv[1]), argv[2], argv[3]);
                    break;
                case 2:
                    distance(atoi(argv[1]), argv[2], argv[3]);
                    break;
                case 3:
                    mass(atoi(argv[1]), argv[2], argv[3]);
                    break;
            }
            break;
        default:
            printf("Error:\nMust enter your desired units on the command line. Output changes based on format of input.\n\n\"25 unit unit2\" for specific conversions from the first unit to the second.\n\"25 unit\" for general conversions for the amount of unit specified.\n\"unit unit2\" for specific conversions of value 1.\n\"unit\" for basic conversions of 1 of the specified starting unit.\n\nExamples:\n\"25 Celsius Fahrenheit\" returns \"25.00°C ---> 77.00°F\"\n\"25 Celsius\" returns \"25.00°C ---> 77.00°F || 298.15K\"\n\"Celsius Fahrenheit\" returns \"1.00°C ---> 33.80°F\"\n\"Celsius\" returns \"1.00°C ---> 33.80°F || 274.15K\"\n\nFor a list of all accepted units and variations, type \"Units\" in the command line prompt.");
            printf("\n");
            return 0;
    }
    printf("\n");
}

void temperature(int x, char* n, char* m)
{
    //make the temperatures all uniform in their presentation with first letter capitalization
    char y = toupper(n[0]);
    n[0] = y;
    char z = toupper(m[0]);
    m[0] = z;

    // variables to check to see if return unit is valid and return an error if it is not
    int valid = 0;

    // celsius, kelvin, fahrenheit
    float celsius = 0;
    float fahrenheit = 0;
    float kelvin = 0;

    // check to see if user is converting celsius
    if (strcmp(n, "C") == 0 || strcmp(n, "Celsius") == 0)
    {
        // do celsius conversions
        celsius = x;
        fahrenheit = (celsius * 9/5) + 32;
        kelvin = celsius + 273.15;

        //if user did put in exact conversion, return it
        for (int i = 0; i < 6; i++)
        {
            if (strcmp(m,temp_units[i]) == 0)
            {
                if (strcmp(temp_units[i],"F") == 0 || strcmp(temp_units[i],"Fahrenheit") == 0)
                {
                    valid++;
                    printf("%.02f°C ---> %.02f°%s\n", celsius, fahrenheit, temp_units[i]);
                }
                else
                {
                    valid++;
                    printf("%.02f°C ---> %.02f%s\n", celsius, kelvin, temp_units[i]);
                }
            }
        }
    }

    // check to see if the user is doing fahrenheit conversions
    if (strcmp(n, "F") == 0 || strcmp(n, "Fahrenheit") == 0)
    {
        // do fahrenheit conversions
        fahrenheit = x;
        celsius = (fahrenheit - 32) * 5/9;
        kelvin = (fahrenheit - 32) * 5/9 + 273.15;

        // find the accurate information for that specific temperature type
        for (int i = 0; i < 6; i++)
        {
            if (strcmp(m,temp_units[i]) == 0)
            {
                if (strcmp(temp_units[i],"C") == 0 || strcmp(temp_units[i],"Celsius") == 0)
                {
                    valid++;
                    printf("%.02f°F ---> %.02f°%s\n", fahrenheit, celsius, temp_units[i]);
                }
                else
                {
                    valid++;
                    printf("%.02f°F ---> %.02f%s\n", fahrenheit, kelvin, temp_units[i]);
                }
            }
        }
    }

    // check to see if user is doing kelvin conversions
    if (strcmp(n, "K") == 0 || strcmp(n, "Kelvin") == 0)
    {
        // do kelvin conversions
        kelvin = x;
        celsius = kelvin - 273.15;
        fahrenheit = celsius * 9/5 + 32;

        // find the exact return type temperature
        for (int i = 0; i < 6; i++)
        {
            if (strcmp(m,temp_units[i]) == 0)
            {
                if (strcmp(temp_units[i],"C") == 0 || strcmp(temp_units[i],"Celsius") == 0)
                {
                    valid++;
                    printf("%.02fK ---> %.02f°%s\n", kelvin, celsius, temp_units[i]);
                }
                else
                {
                    valid++;
                    printf("%.02fK ---> %.02f°%s\n", kelvin, fahrenheit, temp_units[i]);
                }
            }
        }
    }

    if (valid == 0)
    {
        printf("Error:\nMust be a valid return unit, type \"units\" on the command line for a list of usable units and their variations.\n");
    }
}

void temp_generic(int x, char* n)
{
    // capitalize first letter to ensure it matches our list of unit types
    char y = toupper(n[0]);
    n[0] = y;

    float celsius = x;
    float fahrenheit = 0;
    float kelvin = 0;

    // check to see if user is doing celsius conversions
    if (strcmp(n, "C") == 0 || strcmp(n, "Celsius") == 0)
    {
        // celsius conversion
        celsius = x;
        fahrenheit = (celsius * 9/5) + 32;
        kelvin = celsius + 273.15;

        // return conversions
        printf("%.02f°C ---> %.02f°F || %.02fK", celsius, fahrenheit, kelvin);
    }

    // check to see if user is doing fahrenheit conversions
    if (strcmp(n, "F") == 0 || strcmp(n, "Fahrenheit") == 0)
    {
        fahrenheit = x;
        celsius = (fahrenheit - 32) * 5/9;
        kelvin = (fahrenheit - 32) * 5/9 + 273.15;

        // return conversions
        printf("%.02f°F ---> %.02f°C || %.02fK", fahrenheit, celsius, kelvin);
    }

    // check to see if user is doing kelvin conversions
    if (strcmp(n, "K") == 0 || strcmp(n, "Kelvin") == 0)
    {
        kelvin = x;
        celsius = kelvin - 273.15;
        fahrenheit = celsius * 9/5 + 32;

        // return conversions
        printf("%.02fK ---> %.02f°C || %.02f°F", kelvin, celsius, fahrenheit);
    }
    printf("\n");
}

void distance(int x, char* n, char* m)
{

    // make presentation universal through capitalization
    char y = toupper(n[0]);
    n[0] = y;
    char z = toupper(m[0]);
    m[0] = z;

    // variable to check if the return unit is a valid unit
    int valid = 0;

    // declare units that will be used in this function
    float kilometer = 0;
    float feet = 0;
    float meter = 0;
    float yard = 0;
    float mile = 0;

    // check to see if user is converting kilometers
    if (strcmp(n,"Kilometers") == 0 || strcmp(n,"Kilometer") == 0 || strcmp(n,"Km") == 0)
    {
        //do kilometer conversions
        kilometer = x;
        feet = kilometer * 3280.84;
        meter = kilometer * 1000;
        yard = kilometer * 1093.61;
        mile = kilometer / 1.609;

        // ensure number in print ouput matches value selected for units type
        float num[11] = {kilometer, kilometer, kilometer, meter, meter, mile, mile, yard, yard, feet, feet};

        // convert for the specific output specified by the user
        for (int i = 0; i < 11; i++)
        {
            if (strcmp(dist_units[i], m) == 0)
            {
                valid++;
                printf("%0.2f kilometers ---> %.02f %s\n", kilometer, num[i], dist_units[i]);
            }
        }
    }

    // check to see if user is doing meter conversions
    if (strcmp(n,"Meters") == 0 || strcmp(n,"Meter") == 0)
    {
        // meter calculations
        meter = x;
        kilometer = meter / 1000;
        mile = meter / 1609;
        yard = meter * 1.094;
        feet = meter * 3;

        // ensure number in print ouput matches value selected for units type
        float num[11] = {kilometer, kilometer, kilometer, meter, meter, mile, mile, yard, yard, feet, feet};

        // find specific output that user specified on commmand line
        for (int i = 0; i < 11; i++)
        {
            if (strcmp(dist_units[i],m) == 0)
            {
                valid++;
                printf("%.02f meters ---> %.02f %s\n", meter, num[i], dist_units[i]);
            }
        }
    }

    // check to see if user is doing mile conversions
    if (strcmp(n,"Miles") == 0 || strcmp(n,"Mile") == 0)
    {
        // miles calculations
        mile = x;
        kilometer = mile * 1.60934;
        yard = mile * 1760;
        feet = mile * 5280;
        meter = mile * 1609.34;

        // ensure number in print ouput matches value selected for units type
        float num[11] = {kilometer, kilometer, kilometer, meter, meter, mile, mile, yard, yard, feet, feet};

        // find specific output that user specified on commmand line
        for(int i = 0; i < 11; i++)
        {
            if (strcmp(dist_units[i], m) == 0)
            {
                valid++;
                printf("%.02f miles ---> %.02f %s\n", mile, num[i], dist_units[i]);
            }
        }
    }

    // check to see if user is doing yard conversions
    if (strcmp(n,"Yards") == 0 || strcmp(n,"Yard") == 0)
    {
        // do yards calculations
        yard = x;
        mile = yard / 1760;
        kilometer = yard / 1094;
        meter = yard / 1.094;
        feet = yard * 3;

        // ensure number in print ouput matches value selected for units type
        float num[11] = {kilometer, kilometer, kilometer, meter, meter, mile, mile, yard, yard, feet, feet};

        // find specific output that user specified on commmand line
        for (int i = 0; i < 11; i++)
        {
            if (strcmp(dist_units[i],m) == 0)
            {
                valid++;
                printf("%.02f yards ---> %.02f %s\n", mile, num[i], dist_units[i]);
            }
        }
    }

    // check to see if user is doing feet conversions
    if (strcmp(n,"Feet") == 0 || strcmp(n,"Foot") == 0)
    {
        // do feet conversions
        feet = x;
        yard = feet / 3;
        meter = feet / 3.281;
        kilometer = feet / 3281;
        mile = feet / 5280;

        // ensure number in print ouput matches value selected for units type
        float num[11] = {kilometer, kilometer, kilometer, meter, meter, mile, mile, yard, yard, feet, feet};

        // find specific output that user specified on commmand line
        for (int i = 0; i < 11; i++)
        {
            if (strcmp(dist_units[i],m) == 0)
            {
                valid++;
                printf("%.02f feet ---> %.02f %s\n", feet, num[i], dist_units[i]);
            }
        }
    }

    if (valid == 0)
    {
        printf("Error:\nMust be a valid return unit, type \"units\" on the command line for a list of usable units and their variations.\n");
    }
}

void dist_generic(int x, char* n)
{
    // capitalize first letter to ensure it matches our list of unit types
    char y = toupper(n[0]);
    n[0] = y;

    // initialize variables
    float kilometer = 0;
    float feet = 0;
    float meter = 0;
    float yard = 0;
    float mile = 0;

    // check to see if user is doing kilometer conversions
    if (strcmp(n,"Kilometers") == 0 || strcmp(n,"Kilometer") == 0 || strcmp(n,"Km") == 0 )
    {
        // do kilometer conversions
        kilometer = x;
        feet = kilometer * 3280.84;
        meter = kilometer * 1000;
        yard = kilometer * 1093.61;
        mile = kilometer / 1.609;

        printf("%.02f kilometers ---> %.02f feet || %.02f yards || %.02f meters || %.02f miles", kilometer, feet, yard, meter, mile);
    }

    // check to see if user is doing meter conversions
    if (strcmp(n,"Meters") == 0 || strcmp(n,"Meter") == 0)
    {
        // do meter conversions
        meter = x;
        kilometer = meter / 1000;
        mile = meter / 1609;
        yard = meter * 1.094;
        feet = meter * 3;

        printf("%.02f meters ---> %.02f feet || %.02f yards || %.02f kilometers || %.02f miles", meter, feet, yard, kilometer, mile);
    }

    // check to see if user is doing mile conversions
    if (strcmp(n,"Miles") == 0 || strcmp(n,"Mile") == 0)
    {
        // do mile conversions
        mile = x;
        kilometer = mile * 1.60934;
        yard = mile * 1760;
        feet = mile * 5280;
        meter = mile * 1609.34;

        printf("%.02f miles ---> %.02f feet || %.02f yards || %.02f meters || %.02f kilometers", mile, feet, yard, meter, kilometer);
    }

    // check to see if user is doing yard conversions
    if (strcmp(n,"Yards") == 0 || strcmp(n,"Yard") == 0)
    {
        // do yard conversions
        yard = x;
        mile = yard / 1760;
        kilometer = yard / 1094;
        meter = yard / 1.094;
        feet = yard * 3;

        printf("%.02f yards ---> %.02f feet || %.02f meters || %.02f kilometers || %.02f miles", yard, feet, meter, kilometer, mile);
    }

    // check to see if user is doing feet conversions
    if (strcmp(n,"Feet") == 0 || strcmp(n,"Foot") == 0)
    {
        // do feet conversions
        feet = x;
        yard = feet / 3;
        meter = feet / 3.281;
        kilometer = feet / 3281;
        mile = feet / 5280;

        printf("%.02f feet ---> %.02f yards || %.02f meters || %.02f kilometers || %.02f miles", feet, yard, meter, kilometer, mile);
    }
    printf("\n");
}

void mass(int x,char* n, char* m)
{
    // capitalize first letter to ensure it matches our list of unit types
    char y = toupper(n[0]);
    n[0] = y;
    char z = toupper(m[0]);
    m[0] = z;

    // variable to check if return unit is of a valid type
    int valid = 0;

    // declare variables for this function
    float pound = 0;
    float ounce = 0;
    float gram = 0;
    float kilogram = 0;

    // pound, ounce, kilogram, gram
    if (strcmp(n,"Pounds") == 0 || strcmp(n,"Lbs") == 0 || strcmp(n,"Pound") == 0)
    {
        // do pound conversions
        pound = x;
        ounce = pound * 16;
        gram = pound * 453.6;
        kilogram = pound / 2.205;

        // ensure number output mimics output unit type
        float num[11] = {pound, pound, pound, ounce, ounce, ounce, gram, gram, kilogram, kilogram, kilogram};

        //return the specific unit type that user specified
        for (int i = 0; i < 11; i++)
        {
            if (strcmp(mass_units[i],m) == 0)
            {
                valid++;
                printf("%.03f lbs ---> %.03f %s\n", pound, num[i], mass_units[i]);
            }
        }
    }

    // check to see if user is doing ounce conversions
    else if (strcmp(n,"Ounces") == 0 || strcmp(n,"Ounce") == 0 || strcmp(n,"Oz") == 0)
    {
        // do ounce conversions
        ounce = x;
        pound = ounce / 16;
        gram = ounce * 28.35;
        kilogram = ounce / 35.274;

        // ensure number output matches output unit type
        float num[11] = {pound, pound, pound, ounce, ounce, ounce, gram, gram, kilogram, kilogram, kilogram};

        // return the specific unit type and value for that unit type
        for (int i = 0; i < 11; i++)
        {
            printf("%d", i);
            if (strcmp(mass_units[i],m) == 0)
            {
                valid++;
                printf("%.03f ounces ---> %.03f %s\n", ounce, num[i], mass_units[i]);
            }
        }
    }

    // check to see if user is doing gram conversions
    else if (strcmp(n,"Gram") == 0 || strcmp(n,"Grams") == 0)
    {
        // do gram conversions
        gram = x;
        ounce = gram / 28.35;
        pound = gram / 453.6;
        kilogram = gram / 1000;

        // ensure number output is the same as output unit type
        float num[11] = {pound, pound, pound, ounce, ounce, ounce, gram, gram, kilogram, kilogram, kilogram};

        // return the specific unit type and value for the user
        for (int i = 0; i < 11; i++)
        {
            if (strcmp(mass_units[i],m) == 0)
            {
                valid++;
                printf("%.03f grams ---> %.03f %s\n", gram, num[i], mass_units[i]);
            }
        }
    }

    // check to see if user is doing kilogram conversions
    else if (strcmp(n,"Kilogram") == 0 || strcmp(n,"Kg") == 0 || strcmp(n,"Kilograms") == 0 )
    {
        // do kilogram conversions
        kilogram = x;
        ounce = kilogram * 35.274;
        gram = kilogram * 1000;
        pound = kilogram * 2.205;

        // ensure the number matches the unit type in final output
        float num[11] = {pound, pound, pound, ounce, ounce, ounce, gram, gram, kilogram, kilogram, kilogram};

        for (int i = 0; i < 11; i++)
        {
            if (strcmp(mass_units[i],m) == 0)
            {
                valid++;
                printf("%.03f kilograms ---> %.03f %s\n", kilogram, num[i], mass_units[i]);
            }
        }
    }

    if (valid == 0)
    {
        printf("Error:\nMust be a valid return unit, type \"units\" on the command line for a list of usable units and their variations.\n");
    }
}

void mass_generic(int x, char* n)
{
    // capitalize first letter to ensure it matches our list of unit types
    char y = toupper(n[0]);
    n[0] = y;

    //initialize essential variables for function
    float pound = 0;
    float ounce = 0;
    float gram = 0;
    float kilogram = 0;

    // check to see if user is doing pound conversions
    if (strcmp(n,"Pounds") == 0 || strcmp(n,"Pound") == 0|| strcmp(n,"Lbs") == 0)
    {
        // do pound conversions
        pound = x;
        ounce = pound * 16;
        gram = pound * 453.6;
        kilogram = pound / 2.205;

        // return all pound conversions
        printf("%.02f lbs ---> %.03f ounces || %.03f grams || %.03f kilograms", pound, ounce, gram, kilogram);
    }

    // check to see if user is doing ounce conversions
    if (strcmp(n,"Ounces") == 0 || strcmp(n,"Ounce") == 0 || strcmp(n,"Oz") == 0)
    {
        // do ounce conversions
        ounce = x;
        pound = ounce / 16;
        gram = ounce * 28.35;
        kilogram = ounce / 35.274;

        // return all conversions for ounces
        printf("%.02f ounces ---> %.03f lbs || %.03f grams || %.03f kilograms", ounce, pound, gram, kilogram);
    }

    // check to see if user is doing gram conversions
    if (strcmp(n,"Gram") == 0 || strcmp(n,"Grams") == 0)
    {
        // do gram conversions
        gram = x;
        ounce = gram / 28.35;
        pound = gram / 453.6;
        kilogram = gram / 1000;

        // return all gram conversions
        printf("%.02f gram ---> %.03f ounces || %.03f lbs || %.03f kilograms", gram, ounce, pound, kilogram);
    }

    // check to see is user is doing kilogram conversions
    if (strcmp(n,"Kilogram") == 0 || strcmp(n,"Kg") == 0 || strcmp(n,"Kilograms") == 0 )
    {

        // do kilogram conversions
        kilogram = x;
        ounce = kilogram * 35.274;
        gram = kilogram * 1000;
        pound = kilogram * 2.205;

        // return all kilogram conversions
        printf("%.02f kilograms ---> %.03f ounces || %.03f grams || %.03f lbs", kilogram, ounce, gram, pound);
    }
    printf("\n");
}