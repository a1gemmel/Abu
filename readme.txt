Algorithm Benchmarking Utility

Goals

- test and evaluate programs on common test suites
- calculate complexity estimates
- Benchmark runtimes
- compatibility through make
- data output to csv

Workflow
- bash script is called
  - runs make on each directory
  - hands list of directories and test directory to C program
  - C program feeds file input to programs
  - Tests are timed
  - Tests of n complexity are run 
  - approximate complexity is estimated
  - data is saved in csv format

