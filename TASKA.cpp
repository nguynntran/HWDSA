#include <iostream>
#include <vector>
bool BinarySearch(const int* begin, const int* end, int target) {
  while (begin < end) {
    const int* mid = begin + (end - begin) / 2;
    if (*mid == target) {
      return true;
    }
    if (*mid < target) {
      begin = mid + 1;
    } else {
      end = mid;
    }
  }
  return false;
}

int main() {
  int N, Q;
  std::cin >> N;
  std::vector<int> arr(N);

  for (int i = 0; i < N; ++i) {
    std::cin >> arr[i];
  }
  std::cin >> Q;

  for (int k = 0; k < Q; ++k) {
    int i, j, t;
    std::cin >> i >> j >> t;

    const int* begin = &arr[i];
    const int* end = &arr[j];
    bool result = BinarySearch(begin, end, t);
    std::cout << (result ? "YES" : "NO") << std::endl;
  }
  return 0;
}