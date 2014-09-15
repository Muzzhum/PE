#include <iostream>
#include <cmath>
#include <vector>

using namespace std;


void sumsDivisible(int problem) //Project Euler problem 1
{
    int nSum = 0;
    for (int nCount = 1 ; nCount < problem ; nCount++)
    {

        if (nCount % 3 == 0 || nCount % 5 == 0)
            nSum += nCount;
    };
    cout << nSum << endl;
}

void fibonacciSums(int problem) //Project Euler problem 2
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
    } while (y <= problem);

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



void primeLister(long long topLim, vector<long long> &primeList) // Makes a list of primes
{


    for (long long possiblePrime = 5 ; possiblePrime <= topLim ;possiblePrime += 2)
    {
        bool isPrime = true;
        for (unsigned int counter = 0;counter < primeList.size();counter++)
        {
            if (possiblePrime % primeList.at(counter) == 0)
            {
                isPrime = false;
                break;
            }
        }
        if (isPrime)
            primeList.push_back(possiblePrime);
    }
}

void primeFactors(long long problem) //Project Euler problem 3 unfinished
{
    vector<long long> primes(1, 2);
    primes.push_back(3);

    vector<long long> primeList;
    primeLister(problem, primes);

    for (unsigned int counter = 0; counter < primes.size(); counter++)
    {
        if (problem % primes.at(counter))
        {
            primeList.push_back(primes.at(counter));
            problem /= primes.at(counter);
        }

    }

    for (int iii = 0 ; iii < primeList.size() ; iii++)
        cout << primeList.at(iii) << " " ;


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
    primeFactors(24);

    return 0;
}
