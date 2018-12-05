/**
 * This simple program measures the performance of different implementations functions in ORC's RLEV2Util.
 */

#include <iostream>
#include <sys/time.h>

#include "RLEV2Util.hh"

// return timestamp in micro-seconds
static double gettimestamp()
{
  struct timeval tv;
  gettimeofday(&tv, NULL); 
  return (double)tv.tv_sec * 1000000.0 + tv.tv_usec;
}

// total number of function calls
static const long test_num = 2000000000; 

static void test_decodeBitWidth()
{
  const uint32_t max_n = orc::FixedBitSizes::SIZE; // input n is within [0, FixedBitSizes::SIZE-1]
  std::cout << "decodeBitWidth(): " << std::endl;

  {
    double start_time = gettimestamp();
    uint32_t temp = 0;
    for (long i = 0; i < test_num; i++) {
      uint32_t n = i % max_n; 
      temp += orc::decodeBitWidth(n);
    }
    double end_time = gettimestamp();
    std::cout << "original implementation:" << std::endl;
    std::cout << " sum:  " << temp << std::endl;
    std::cout << " time: " << (end_time - start_time) << " micro-seconds" << std::endl;
  }

  { 
    double start_time = gettimestamp();
    uint32_t temp = 0; 
    for (long i = 0; i < test_num; i++) {
      uint32_t n = i % max_n;
      temp += orc::decodeBitWidth_new(n);
    }
    double end_time = gettimestamp();
    std::cout << "new implementation:" << std::endl;
    std::cout << " sum:  " << temp << std::endl;
    std::cout << " time: " << (end_time - start_time) << " micro-seconds" << std::endl << std::endl;
  }
}

static void test_getClosestFixedBits()
{   
  const uint32_t max_n = 66; // input n is within [0, 65]
  std::cout << "getClosestFixedBits():" << std::endl;

  {     
    double start_time = gettimestamp();
    uint32_t temp = 0;
    for (long i = 0; i < test_num; i++) {
      uint32_t n = i % max_n;
      temp += orc::getClosestFixedBits(n);
    }
    double end_time = gettimestamp();
    std::cout << "original implementation:" << std::endl;
    std::cout << " sum:  " << temp << std::endl;
    std::cout << " time: " << (end_time - start_time) << " micro-seconds" << std::endl;
  } 
    
  {     
    double start_time = gettimestamp();
    uint32_t temp = 0;
    for (long i = 0; i < test_num; i++) {
      uint32_t n = i % max_n; 
      temp += orc::getClosestFixedBits_new(n);
    }
    double end_time = gettimestamp();
    std::cout << "new implementation:" << std::endl;
    std::cout << " sum:  " << temp << std::endl;
    std::cout << " time: " << (end_time - start_time) << " micro-seconds" << std::endl << std::endl;
  }
}

static void test_getClosestAlignedFixedBits()
{   
  const uint32_t max_n = 66; // input n is within [0, 65]
  std::cout << "getClosestAlignedFixedBits():" << std::endl;

  {
    double start_time = gettimestamp();
    uint32_t temp = 0;
    for (long i = 0; i < test_num; i++) {
      uint32_t n = i % max_n;
      temp += orc::getClosestAlignedFixedBits(n);
    }
    double end_time = gettimestamp();
    std::cout << "original implementation:" << std::endl;
    std::cout << " sum:  " << temp << std::endl;
    std::cout << " time: " << (end_time - start_time) << " micro-seconds" << std::endl;
  } 
    
  {
    double start_time = gettimestamp();
    uint32_t temp = 0;
    for (long i = 0; i < test_num; i++) {
      uint32_t n = i % max_n;
      temp += orc::getClosestAlignedFixedBits_new(n);
    }
    double end_time = gettimestamp();   
    std::cout << "new implementation:" << std::endl;
    std::cout << " sum:  " << temp << std::endl;
    std::cout << " time: " << (end_time - start_time) << " micro-seconds" << std::endl << std::endl;
  }
}

static void test_encodeBitWidth()
{   
  const uint32_t max_n = 65; // input n is within [0, 64]
  std::cout << "encodeBitWidth():" << std::endl;

  {
    double start_time = gettimestamp();
    uint32_t temp = 0;
    for (long i = 0; i < test_num; i++) {
      uint32_t n = i % max_n;
      temp += orc::encodeBitWidth(n);
    }
    double end_time = gettimestamp();
    std::cout << "original implementation:" << std::endl;
    std::cout << " sum:  " << temp << std::endl;
    std::cout << " time: " << (end_time - start_time) << " micro-seconds" << std::endl;
  } 
    
  {
    double start_time = gettimestamp();
    uint32_t temp = 0;
    for (long i = 0; i < test_num; i++) {
      uint32_t n = i % max_n;
      temp += orc::encodeBitWidth_new(n);
    }
    double end_time = gettimestamp();
    std::cout << "new implementation:" << std::endl;
    std::cout << " sum:  " << temp << std::endl;
    std::cout << " time: " << (end_time - start_time) << " micro-seconds" << std::endl << std::endl;
  }
}

int main() 
{
  test_decodeBitWidth();
  test_getClosestFixedBits();
  test_getClosestAlignedFixedBits();
  test_encodeBitWidth();
  
  return 0;
}

