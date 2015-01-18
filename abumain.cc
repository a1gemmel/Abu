// ABU - Algorithm Benchmark Tool
// Andrew Gemmel 2014
// C++ Program that does work... son

#include <iostream>
#include <fstream>
#include <time.h>
#include <string>
#include <sstream>
#include <stdlib.h>

using namespace std;

int main (int argc, char *argv[]) {

  string Num_Tests_String = argv[1];
  string TestSuite_Directory = argv[2];
  string Solution_Directory = argv[3];
  stringstream ss(Num_Tests_String);
  int Num_Tests;
  ss >> Num_Tests;
  
  char **test_index = (argv + 4);
  const int Num_Programs = argc - Num_Tests - 4;
  char **program_index = (argv + 4 + Num_Tests);

  ofstream csv("abu.csv");
  
  /* populate first row of spreadsheet
    Spreadsheet will take form:
        , Testname, Testname2, Testname3, Testname4,
Program1,   3.5789,    123456,     69.69,        12,
Program2,     5.56,    123456,      9001,        42,
   */
  csv << ","; // empty tile for formatting
  for (int test = 0; test < Num_Tests; test++) {
    csv << " " << test_index[test] << ",";
  }
  csv << endl;

  for (int prog = 0; prog < Num_Programs; prog++) {
    
    string program_folder_name = program_index[prog];
    csv <<  program_folder_name << ",";
    
    for (int test = 0; test < Num_Tests; test++) {
      
      string test_file_name = test_index[test];
      string program_folder_name = program_index[prog];
      

      
      // Call the program piping input from the testSuite and
      // output to the program's folder in the format:
      // programname-testname.out
      // never try this at home, kids
	  string syscall = Solution_Directory + "/" + program_folder_name 
	     + "/main.exe < " + TestSuite_Directory + "/" + test_file_name 
	     + " > " + Solution_Directory + "/" + program_folder_name
	     + "/" + program_folder_name + "-" + test_file_name + ".out";
	
	clock_t pre_run_timestamp = clock();
      system(syscall.c_str());
    clock_t post_run_timestamp = clock();
      
	  double time_taken = post_run_timestamp - pre_run_timestamp;
      csv << time_taken << ",";
    }
	csv << endl;
  }

}
