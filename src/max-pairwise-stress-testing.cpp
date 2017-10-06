#include <cstdlib>
#include <iostream>
#include <vector>

/*
 * DUC LUU'S ALGORITHM IMPLEMENTAIONS
 *
 *  /\  |  _   _   _ o _|_ |_  o  _ _  _ 
 * /--\ | (_| (_) |  |  |_ | | | | | | > 
 *         _|                      
 *
 * Max pairwise product with stress testing strategy
 *
 * Overview:
 * 		(1) Problem: Given a sequence of non-negative integers a0,,an1, find the maximum pairwise product, that is, 
 *                   the largest integer that can be obtained by multiplying two different elements from the sequence
 *
 *      (2) Stress testing: The idea behind stress testing is that if you have two correct solutions, and the answer to the problem is unique, 
 *                          then for any possible test case they are guaranteed to give the same answer. If, however, at least one of the solutions is incorrect, 
 *                          then with very high probability there exists a test on which their answers differ. 
 *
 * ------------
 *
 * Referenced links:
 * 1. https://www.coursera.org/learn/algorithmic-toolbox
 *
 * 
 */

using std::vector;
using std::cin;
using std::cout;

long long MaxPairwiseProduct(const vector<int>& numbers) {
  long long result = 0;
  int n = numbers.size();
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (((long long)(numbers[i])) * numbers[j] > result) {
        result = ((long long)(numbers[i])) * numbers[j];
      }
    }
  }
  return result;
}

long long MaxPairwiseProductFast(const vector<int>& numbers) {
  int n = numbers.size();

  int max_index1 = -1;
  for (int i = 0; i < n; ++i)
    if ((max_index1 == -1) || (numbers[i] > numbers[max_index1]))
      max_index1 = i;

  int max_index2 = -1;
  for (int j = 0; j < n; ++j)
    if ((numbers[j] != numbers[max_index1]) && ((max_index2 == -1) || (numbers[j] > numbers[max_index2])))
      max_index2 = j;

  return ((long long)(numbers[max_index1])) * numbers[max_index2];
}

int main() {
  while (true) {
    int n = rand() % 10 + 2;
    cout << n << "\n";
    vector<int> a;
    for (int i = 0; i < n; ++i) {
      a.push_back(rand() % 100000);
    }
    for (int i = 0; i < n; ++i) {
      cout << a[i] << ' ';
    }
    cout << "\n";
    long long res1 = MaxPairwiseProduct(a);
    long long res2 = MaxPairwiseProductFast(a);
    if (res1 != res2) {
      cout << "Wrong answer: " << res1 << ' ' << res2 << "\n";
      break;
    }
    else {
      cout << "OK\n";
    }
  }
  int n;
  cin >> n;
  vector<int> numbers(n);
  for (int i = 0; i < n; ++i) {
    cin >> numbers[i];
  }

  long long result = MaxPairwiseProductFast(numbers);
  cout << result << "\n";
  return 0;
}

