/***************************************
NAME:   primeFactors.cpp
AUTHOR: Edwin Langley
DESC:   This program will return a list of unsigned long ints, the product of which equals the argument passed into the function 

SOURCES: 
----------------------------------------
http://www.cplusplus.com/reference/cmath/sqrt/
https://en.wikipedia.org/wiki/Prime_number
http://www.cplusplus.com/reference/list/list/push_back/
https://softwareengineering.stackexchange.com/questions/318055/how-much-do-function-calls-impact-performance
----------------------------------------

***************************************/

//Takes and includes libraries and function prototypes that are necessary for the function.
#include "primeFactors.h"

//Removes the need to use std:: infront of standard functions, lists etc
using namespace std;

//primeFactors function
list<unsigned long int> primeFactors(unsigned long int factorNumber)
{
    //list to hold prime factors
    list<unsigned long int> FList = {};

    //Test to see if the entered number is equal to 0 or 1. This is because both of these numbers 
    //do not have factors.

    //The definition of a Prime Number is "A number that is divisible only by itself and 1"
    //Neither 0 or 1 have a magnitude greater than 1 so therefore they cannot have a factor larger than 1

    if ((factorNumber == 0) || (factorNumber == 1))
    {
        FList = {};
        return FList;
    }

    unsigned long counter = 2;

    //While the factor number is divisible by the 2, record this number and divide factorNumber by 2
    //This shows that as long as the number is even - it can be halved and therefore 2 is a prime factor

    while(factorNumber % counter == 0){
        FList.push_back(counter);
        factorNumber/=counter;
    }

    counter=3;

    //While the counter (now 3) is smaller than factorNumber divided by itself, check to see if the counter 
    //is a divisor of factorNumber. 

    //The While check can also be written as counter <= sqrt(factorNumber),

    //PROOF
    //=================================
    //counter <= factorNumber / counter
    //counter^2 <= factorNumber
    //counter <= sqrt(factorNumber)
    //=================================

    //however despite being the same thing as counter <= factorNumber / counter, a call to sqrt in cmath is expensive
    //compared to a single divide. The sqrt() function is also very accurate as it is designed to work with floats
    //but this is expensive in terms of processing time.

    //The reason we only check up to factorNumber / counter is because if a number is not a prime it will have
    //two factors x and y, if both of these numbers were greater than the squareroot of factorNumber then x * y
    //would be larger than factorNumber.

    //We know for certain that even numbers are not prime numbers as they are divisible by 2. For this reason,
    //we should iterate the counter by 2 rather than 1 as to follow the pattern 3,5,7,9 etc -
    //this halves the amount of checks we need to do.

    while(counter <= factorNumber / counter)
    {
        if(factorNumber % counter ==0)
        {
            FList.push_back(counter);
            factorNumber /= counter;
        } else {
            counter+=2;
        }
    }

    //If a number fails to be divisible by a number smaller than factorNumber / counter it means
    //that it is a prime number and a factor of the original factorNumber entered into the function.
    
    if(factorNumber > 1)
    {
        FList.push_back(factorNumber);
    }

    //Returns the list of factors out of the function.
    return FList;
}

