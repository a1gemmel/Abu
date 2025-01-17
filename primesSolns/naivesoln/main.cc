// naive prime output


#include <iostream>
#include <sstream>
#include <string>
#include <cmath>

using namespace std;


int main(int argc, char *argv[]) {
  
  stringstream ss(argv[1]);
  int max;
  ss >> max;
  
  
  for (int i = 2; i < max; i++) {
    bool isPrime = true;
    for (int j = 2; j < i; j++) {
      isPrime = fmin(isPrime, (i % j != 0));
    }
    if (isPrime) {
      cout << i << endl;
    }
  }
}
