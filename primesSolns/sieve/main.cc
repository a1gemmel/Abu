
#include <iostream>
#include <sstream>
#include <string>



using namespace std;

int main (int argc, char *argv[]) {
  stringstream ss(argv[1]);
  int max;
  ss >> max;
  
  int a[max + 1];
  for (int i = 1; i <= max; i++) {
    a[i] = i;
  }

  for (int i = 2; i <= max; i++) {
    if (a[i] != 0) {
      cout << i << "\n";
      for (int m = i; m * i < max; m++) {
	a[m * i] = 0;
      }
    }
  }
}