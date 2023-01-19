# CS50-Project
# Project Title: Conversion

#### Video demo: https://www.youtube.com/watch?v=rKgbF8RlAhI

#### Description:
My project is a simple command-line C unit conversion program. I designed it so that it would have multiple different values that it could use for each of the three types included which are: temperature, distance, and mass. I also included multiple variations for each unit including many shortened versions and the standard long versions of the units. The program is also caps-insensitive and will convert any input to the capital version in order to have a uniform list of variables to use when checking against the included units. I tried to account for the ways that a user might think to input their units to get it converted, and I feel like I was relatively successful in that regard, although I am sure there are improvements that could be made. I even included failsafes for if the user runs the program with no input that returns a guide on how to properly use the program, as well as a seperate command for a complete list of units and their variations available for use in the program. The program accepts input in four different layouts with those being: "integer unit(1) unit(2)", "unit(1) unit(2)", "integer unit(1)", and "unit(1)". "Integer unit(1) unit(2)" will return a targeted conversion of the specified amount of the starting unit(1) into the return unit(2). "Unit(1) unit(2)" with return a targeted conversion of the specified unit, but without specifying an amount of that unit, it will always default to one. "Integer unit(1)" will give a generic conversion of the specified amount of the unit in the command line and return conversions for all available units in that field. "Unit" will always return the generic conversion for the specified unit and will always do so with a value of one implied by not inputing a specific amount on the command line.

In main it determines, based on the user input, what kind of unit is being converted out of the available: mass, distance, and temperature. It does this by iterating through the arrays of "temp_units", "mass_units", and "dist_units" until it finds a match. If none of the arrays contain a matching string as the one the user input, it will return an error saying specifying where to find the available units and the format required in this program. Once it has figured out which type of units it is using, it saves the corresponding integer in a variable named "units". The program will then check "argc" to see the length and amount of agruements specified by the user. It does this so that it knows which function it should use to get the desired output. Once "units" has a integer stored in it that is not zero, main will use two switch-case functions to narrow down which function needs to be used. The first switch-case takes the integer in "argc" to determine which case it should trigger. Then the second switch-case comes in to play and it uses the integer in "units" to further narrow it down to one remaining function that returns the ideal output. The exception to this being the case of "argc" being three because there are two different potential inputs here that need to be accounted for. The first being the standard generic input of integer-unit such as: "12 Celsius", the other being unit to unit such as: "Celsius fahrenheit". The reason for this being that to get proper output the functions need to be used differently and I determine which needs to be used by using a if-then statement that checks to see if the value in "argv[1]" is an integer or not. It does this like so "if (!(isdigit(j[0])))", which is basically just having the value of "argv[1]" stored in variable J which then has its first value in the array checked by function "isdigit()" and then reversing the function by throwing the "!" at the front of it. Having this if statement included accounts for the different ways the user can input when "argc" is three.

My functions for the different kinds of units in this program are: "temperature", "temp_generic", "mass", "mass_generic", "distance", and "dist_generic". I defined the normal functions and the generic versions for different styles of output where the normal functions return targeted conversions like: "12°C ---> 53.60°F", whereas the generic functions are designed to return more general output such as: "15°C ---> 59.00°F || 288.15K". I did the seperate functions to avoid a recurring segmentation fault that occurred when trying to use the single function for both kinds of output due to the lack of input in cases where the user was not using the full length of the function. In the standard functions it is set up to use "strcmp()" to check the values in the associated spot of "argv[2]". When it finds the type of input that we are starting with it uses that knowledge to do the specific conversations from that unit to the specified unit in "argv[3]". It finds the unit type in "argv[3]" by iterating over the corresponding unit variable, whether that be "temp_units", "mass_units", or "dist_units", and uses "strcmp()" once again until their is a match. Once a match for the output unit type, it prints the output that matches all of the specific conditions, in the case of the temperature function it does a second "strcmp()" check to determine the final output. The generic functions largely function the same way in that they use "strcmp()" to determine the unit type being used in "argv[1]/argv[2]" and use that information to determine the type of conversions being done. So if it determines that "argv[1]" in this case is kilograms, it will do the kilogram specific conversions using the formulas. It then saves all of the conversion values into named variables and uses those named variable to fill out a print statment in which it returns kilograms converted into all available mass units. For example: "1.00 kilograms ---> 35.274 ounces || 1000.000 grams || 2.205" is the return conversion using the generic functions for a kilogram. The decimal place output is three on mass conversions due to the low value of some of the conversions in an attempt to always display something and not just zeros, whereas in the other functions output only two decimal places is neccessary.
