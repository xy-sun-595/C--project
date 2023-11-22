//https://github.com/xy-sun-595/C--project.git
//
//
#include<iostream>
#include<vector> 
#include<cmath>         //For Q4-a sqrt()
using namespace std;

//Q1. Conditional Statements
void conditional_statements(int n) {
    switch (n){
        case -1:                                    // Switch:
            cout << "negative one" << endl;         // when n is -1, display "negative one"
            break;
        case 0:
            cout << "zero" << endl;                 // when n is 0, display "zero"
            break;
        case 1:
            cout << "positive one" << endl;         // when n is 1, display "positive one"
            break;
        default:
            cout << "other value" << endl;          // when n is other integer, display "other"
            break;
    }
}

//Q2. Printing a Vector
void print_vector(vector<int> v) {                  // Display:
    cout << "[";                                    // '['
    for (int i=0; i<v.size(); i++){                 // Loop through 0 to the size of vector
        cout << v[i];                               // print the i-th element
        cout << ",";
    }
    cout << "]" << endl;                            // ']'
}

//Q3. While Loops
void getFibonacci(vector<int>& f, int upper){
    int temp = 0;                                   // Initialize temp
    int f1 = 1, f2 = 2;                             // Set the first two terms: 1, 2
    f.push_back(f1);                                // Collect the first two terms 1, 2
    while (f2 < upper){
        f.push_back(f2);                            // Store f2 which is the sum of temp and f1
        temp = f1;                                  // Use 'temp' to hold the value of f1
        f1 = f2;                                    // Use 'f1' to hold the value of f2
        f2 = temp + f2;                             // the 3rd number is sum of two previous numbers
    }
 }

//Q4. Functions
//4-a. If Prime
bool isprime(int n){
    if (n < 2)                                                  // Prime number is a whole number greater than 1, so we check numbers from 2
        return false;                                           // n is not a prime
    else if(n==2 || n==3)                                       // 2,3 are prime,don't have enough index(from 2 to int(sqrt(3)+1)) to run 'for loop'
        return true;                                            // 2,3 is prime
    else{
        for(int i=2; i<= static_cast<int>(sqrt(n)+1); ++i){     // Use for loop to check from 2 to sqrt(n)+1, [sqrt(n)+1]^2 will be over n
            if(n%i==0)                                          // If n/i is equal to 0 ,which means n is divisible by i (No other factors except 1 and itself)
                return false;                                   // n is not a prime, return value:False
        }
        return true;                                            // otherwise it is prime
    }
    
}
void test_isprime(){                                            // Call isprime() to test:
    cout << "isprime(2) = "<< isprime(2) <<'\n';                    // 1
    cout << "isprime(10) = "<< isprime(10) <<'\n';                  // 0
    cout << "isprime(17) = "<< isprime(17) <<'\n';                  // 1
}

//4-b. Factorize
std::vector<int> factorize(int n){
    std::vector<int> answer;                                    // Use a vector to hold all prime factors for n
    for(int i=1; i<=n; ++i){                                    // Loop through from 1 to n
        if(n % i == 0)                                          // if n is divisible by i
            answer.push_back(i);                                // Collect all the factorizations
    }
    return answer;                                              // Return the vector: answer
}
void test_factorize(){                                          // call the factorize and print out
    print_vector(factorize(2));
    print_vector(factorize(72));
    print_vector(factorize(196));
}

//4-c. Prime Factorization
std::vector<int> prime_factorize(int n){
    std::vector<int> answer;                                    // Use a vector to hold all prime factors for n
    if(isprime(n)){                                             // if n is a prime (prime don't have factors except 1 and itself)
        answer.push_back(n);                                        // The only prime factor is n itself
        return answer;
    }
    else{                                                       // if n is not prime:
        for(int i=2; i<=n; ++i){                                // Loop through 2 to n
            while(n % i == 0 && isprime(i)){                    // Check any prime number (from 2 to n) can be divisible by n
                answer.push_back(i);                            // if it is, Use vector to collect it
                n /= i;                                         // keep divding this number until no more the same factor in n
            }
        }
        return answer;                                          // Return all the prime factors
    }
}
void test_prime_factorization(){                                // Call test_prime_factorization() to test:
    print_vector(prime_factorize(2));
    print_vector(prime_factorize(72));
    print_vector(prime_factorize(196));
}

//Q5. Recursive Functions and Loops
std::vector<int> pascal(int m){
    if (m == 0)                                                 // if m = 0 then it represents the 1st row which is [1]
        return {1};
    else{                                                       // if m != 0
        std::vector<int> last_row = pascal(m-1);                // Call the function pascal(m-1)
        std::vector<int> row = {1};
        for(int i=1; i<m; i++){                                 // Loop though from the 1st element to the (m-1)th element
            int num = last_row[i-1] +last_row[i];               // Each element is the sum of the (i-1)th element and the ith element from last row
            row.push_back(num);                                 // Use "row" to collect all m-1 elements above
        }
        row.push_back(1);                                       // Use "row" to collect the mth element (always 1)
        return row;                                             // Return the list of elements in mth row
    }
}
void print_pascal(){
    int m;
    cout << "Enter a number: ";
    cin >> m;
    for(int i=0; i<m; ++i)                                      // Loop though 1 to m
        print_vector(pascal(i));                                // print out from the 1st row to the m-th row
}


int main(){
    cout << "Q1. Conditional Statements" << endl;       // Q1. Conditional Statements
    int n;
    cout << "Enter a number: ";
    cin >> n;
    conditional_statements(n);

    cout << "\nQ2. Printing a Vector" << endl;          // Q2. Printing a Vector
    vector<int> v1 = {1,2,3,4,5};
    print_vector(v1);

    cout << "\nQ3. While Loops" << endl;                //  Q3. While Loops
    vector<int> fibonacci;
    getFibonacci(fibonacci,4000000);
    print_vector(fibonacci);

                                                        // Q4. Functions
    cout << "\nQ4. Functions:\n a. If Prime" << endl;         // a. If Prime
    test_isprime();
    cout << "\nb. Factorize" << endl;                         // b. Factorize
    test_factorize();
    cout << "\nc. Prime Factorization" << endl;               //c. Prime Factorization
    test_prime_factorization();

    cout << "\nQ5. Recursive Functions and Loops" << endl;// Q5. Recursive Functions and Loops
    print_pascal();

    return 0;
}