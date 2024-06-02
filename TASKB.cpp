#include <iostream>
#include <vector>

// Function to partition the array and return the pivot index
int partition(std::vector<int>& arr, int low, int high) {
  int pivot = arr[high];
  int i = low - 1;

  for (int j = low; j < high; j++) {
    if (arr[j] <= pivot) {
      i++;
      std::swap(arr[i], arr[j]);
    }
  }
  std::swap(arr[i + 1], arr[high]);
  return i + 1;
}

// Function to find the k-th smallest element using QuickSelect algorithm
int quickSelect(std::vector<int>& arr, int low, int high, int k) {
  if (low <= high) {
    int pivotIndex = partition(arr, low, high);

    if (pivotIndex == k)
      return arr[pivotIndex];
    else if (pivotIndex > k)
      return quickSelect(arr, low, pivotIndex - 1, k);
    else
      return quickSelect(arr, pivotIndex + 1, high, k);
  }
  return -1;
}

int main() {
  int n, k, A0, A1;
  std::cin >> n >> k >> A0 >> A1;

  // Generate the sequence
  std::vector<int> sequence(n);
  sequence[0] = A0;
  sequence[1] = A1;
  for (int i = 2; i < n; ++i) {
    sequence[i] =
        (sequence[i - 1] * 123 + sequence[i - 2] * 45) % (10000000 + 4321);
  }

  // Find the k-th order statistic
  int kOrderStatistic = quickSelect(sequence, 0, n - 1, k - 1);

  std::cout << kOrderStatistic << std::endl;

  return 0;
}
