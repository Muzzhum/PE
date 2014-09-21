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

        if (topLim % possiblePrime == 0)
            topLim /= possiblePrime;

    }
}

void primeFactors(long long problem) //Project Euler problem 3
{
    cout << problem << endl;

    vector<long long> primes;
    primes.push_back(2);
    primes.push_back(3);

    vector<long long> primeList;
    primeLister(problem, primes);

    cout << primes.size() << endl;

    for (unsigned int counter = 0; counter < primes.size(); )
    {
        if (problem % primes.at(counter) == 0)
        {
            primeList.push_back(primes.at(counter));
            problem /= primes.at(counter);
        } else
        {
            counter++;
        }

    }

    for (int iii = 0 ; iii < primeList.size() ; iii++)
        cout << primeList.at(iii) << " " ;


}

bool isPalindrome(vector<char> problem) // Checks if numbers are palindrome numbers
{
    bool palindrome = true;       // If this is true, problem is palindrome
    int length = problem.size();  //Length of the problem
    cout << endl << length << endl;

    //This loop will check each element in problem and see if it is equal to the
    //one that is in spot length-iii
    for (int iii = 0 ; iii < length / 2; iii++)
        if (problem.at(iii) != problem.at(length - iii - 1)) //-1 because of how vectors .at() works
            palindrome = false;  // if the above statement is true, number is not palindrome


    return palindrome;
}

int largestPalindromeProduct(int numOfCiphers) // Project Euler problem 4 unfinished
{
    int num = 9119;
    vector<char> str = static_cast<char>(num);

    for (int iii = 0; iii < str.size() ; iii++)
        cout << str.at(iii);
    cout << isPalindrome(str) << endl;

    return 0;
}

int smallestMultiple(int topLim) // Project Euler problem 5 unfinished
{
    /*

    */
}


int main()
{
    largestPalindromeProduct(3);

    return 0;
}
