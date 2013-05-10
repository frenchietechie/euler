#include <cstdint>
#include <cstdio>
#include <vector>

using ::std::vector;

namespace {
int GetSum() {
  int sum = 0;
  for (int i = 0; i < 1000; ++i) {
    if (i % 3 == 0 || i % 5 == 0) {
      sum += i;
    }
  }
  return sum;
}

int GetFibonacci() {
  vector<int> fibonaccis;
  fibonaccis.push_back(1);
  fibonaccis.push_back(2);
  int i = 0;
  int next = 3;
  uint64_t even_sum = 2;
  while (next < 4000000) {
    if (next % 2 == 0) {
      even_sum  += next;
    }
    fibonaccis.push_back(next);
    ++i;
    next = fibonaccis[i] + fibonaccis[i + 1];
  }
  return even_sum;
}

// Stupid implementation of is prime for now.
bool IsPrime(int n) {
  for (int i = 2; i < n; ++i) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}

uint64_t GetLargestPrime() {
  int largest_prime_divider = 2;
  for (uint64_t i = 2; i <= 775147; ++i) {
    if (600851475143 % i == 0 && IsPrime(i)) {
      largest_prime_divider = i;
    }
  }
  return largest_prime_divider;
}

vector<int> Decompose(int n) {
  vector<int> result;
  int k = n;
  while (k > 0) {
    int value = k % 10;
    result.push_back(value);
    k = k - value;
    k = k / 10;
  }
  return result;
}

bool IsPalindrome(int n) {
  vector<int> decomposed = Decompose(n);
  int size = decomposed.size();
  for (int i = 0; i < size / 2; ++i) {
    if (decomposed[i] != decomposed[size - 1 - i]) {
      return false;
    }
  }
  return true;
}

int LargestPalindrome(int max) {
  int largest_palindrome = 0;
  for (int i = 0; i < max; ++i) {
    for (int j = 0; j < max; ++j) {
      int product = i * j;
      if (IsPalindrome(product) && product > largest_palindrome) {
        largest_palindrome = product;
      }
    }
  }
  return largest_palindrome;
}

uint64_t SumSquareDifference(int bound) {
  uint64_t result = 0;
  for (int i = 1; i <= bound; ++i) {
    for (int j = 1; j <= bound; ++j) {
      if (j != i) {
        result += i * j;
      }
	}
  }
  return result;
}
}  // anonymous namespace

int main(int argc, char* argv[]) {
 // printf("Euler 1: %d\n", GetSum());
 // printf("Euler 2: %d\n", GetFibonacci());
 // printf("Euler 3: %ld\n", GetLargestPrime());
 // printf("Euler 4: %d\n", LargestPalindrome(1000));
  printf("Euler 6: %ld\n", SumSquareDifference(100));
  return 0;
}

