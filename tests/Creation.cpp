#include "../Test.h"
#include <iostream>

TEST("Test can be created"){

}

//This should fail as unexpected exception thrown
TEST("Test that throws unexpectedly can be created"){
  setExpectedFailureReason("Unexpected exception thrown.");
  throw "Unexpected";
}

//This test should thrown an unexpected exception, but doesn't
//Missed failure
TEST("Test that should throw unexpectedly can be created"){
  setExpectedFailureReason("Unexpected exception thrown.");
}

TEST_EX("Test with throw can be created", int){
  throw 1;
}

//This test should fail as it does not throw any exception
TEST_EX("Test that never throws can be created", int){
  setExpectedFailureReason("Expected exception type int was not thrown.");
}

//This test should fail as it doesn't throw int exception
TEST_EX("Test that throws wrong type can be created", int){
  setExpectedFailureReason("Unexpected exception thrown.");
  throw "Wrong type.";
}
