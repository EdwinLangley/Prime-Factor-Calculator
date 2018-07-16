
# Variables
INCLUDEDIR = ../headers/
CXXFLAGS   = -std=c++11 -I $(INCLUDEDIR) -Wall -Wfatal-errors -O3

# Search for header files in the specified INCLUDEDIR
vpath %.h $(INCLUDEDIR)

all: primeFactors.o timingTests correctnessTests bestTimingTests bestCorrectnessTests optTimingTests optCorrectnessTests

bestTimingTests: primeFactors-BestStudent_2016-2017.o timingTests.cpp
	g++ $(CXXFLAGS) $^ -o $@ 

bestCorrectnessTests: primeFactors-BestStudent_2016-2017.o correctnessTests.cpp
	g++ $(CXXFLAGS) $^ -lboost_unit_test_framework -o $@ 

optTimingTests: primeFactors-Optimised.o timingTests.cpp
	g++ $(CXXFLAGS) $^ -o $@

optCorrectnessTests: primeFactors-Optimised.o correctnessTests.cpp
	g++ $(CXXFLAGS) $^ -lboost_unit_test_framework -o $@ 

timingTests: primeFactors.o timingTests.cpp
	g++ $(CXXFLAGS) $^ -o $@

correctnessTests: primeFactors.o correctnessTests.cpp
	g++ $(CXXFLAGS) $^ -lboost_unit_test_framework -o $@ 

primeFactors.o: primeFactors.cpp primeFactors.h
	g++ $(CXXFLAGS) -c $< -o $@


clean: 
	rm -f primeFactors.o timingTests correctnessTests bestTimingTests bestCorrectnessTests optTimingTests optCorrectnessTests
