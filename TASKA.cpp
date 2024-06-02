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
  size_t N, Q;
  std::cin >> N;
  std::vector<int> arr(N);

  for (size_t i = 0; i < N; ++i) {
    std::cin >> arr[i];
  }
  std::cin >> Q;

  for (size_t k = 0; k < Q; ++k) {
    size_t i, j;
    int t;
    std::cin >> i >> j >> t;

    if (i >= N || j > N || i > j) {
      std::cout << "NO" << std::endl;
      continue;
    }

    const int* begin = &arr[i];
    const int* end = &arr[j];
    bool result = BinarySearch(begin, end, t);
    std::cout << (result ? "YES" : "NO") << std::endl;
  }
  return 0;
}
