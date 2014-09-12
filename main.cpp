#include <iostream>
#include <cmath>

using namespace std;


void sumsDivisible() //Project Euler problem 1
{
    int nSum = 0;
    for (int nCount = 1 ; nCount < 1000 ; nCount++)
    {

        if (nCount % 3 == 0 || nCount % 5 == 0)
            nSum += nCount;
    };
    cout << nSum << endl;
}

void fibonacciSums() //Project Euler problem 2
{
    int x = 0;
    int y = 1;
    int z;
    int sum = 0;

    do
    {
        z = x + y;
        x = y;
        y = z;
        if (y % 2 == 0)
            sum += y;
    } while (y <= 4000000);

    cout << sum << endl;

}

int primeChecker(long long problem)  //Checks if numbers are prime
{
    /*
    Check if number is prime
        Divide number by all numbers less than up to the number

    */

    for (long counter = 2 ; problem > counter ;)
    {
        if (problem == 2 || problem % counter !=0)
        {
            counter++;
            continue;
        } else
        {
            return 0;
        }

    }
    return problem;
}

void primeFactors(long long problem) //Project Euler problem 3 unfinished
{
    /*
    Find the largest prime factor.
        Check if number is prime
            Use Prime Checker
        Check if sqrt number - counter is prime
    */
    long square = sqrt(problem); //Few numbers have prime factors larger than their own squares
    int answers[64] = { 0 };
    int jjj = 0;

    for (long iii = 2; iii < square; iii++)
    {
        if (primeChecker(square - iii))
        {
            answers[jjj] = primeChecker(square - iii);
            square = primeChecker(square - iii);
            jjj++;
        }
    }
    /*
    long answers[64] = { 0 };
    for (long long iii = 0; iii < (sizeof(answers) / sizeof(answers[0])); iii++)
    {
        if (answers[iii] != 0)
        {
            if (problem % answers[iii] == 0)
            {
                long currentFactor = answers[iii];
                cout << currentFactor << " ";
            }
        }
    }
    */

    for (int iii = 0 ; iii <= 64 ; iii++)
    {

        cout << answers[iii] << " ";
    }

}

void largestPalindromeProduct(int numOfCiphers) // Project Euler problem 4 unfinished
{
    char str[] = "90109";
    int length = 0;
    int iii = 0;
    length = sizeof(str);
    if (length % 2 == 0)
    {
        while (iii < length / 2)
            if (str[iii] = str[length - iii - 1])
                iii++;
            else
                break;
    } else
    {
        while (iii < length / 2 - 0.5)
            if (str[iii] = str[length - iii - 1])
                iii++;
            else
                break;
    }
    cout << length << endl;
}

int smallestMultiple(int topLim) // Project Euler problem 5 unfinished
{
     /*

     */
}


int main()
{
    primeFactors(13195);
    return 0;
}
