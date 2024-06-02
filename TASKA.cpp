#include <iostream>

using namespace std;

// Threshold for switching to insertion sort
const int INSERTION_SORT_THRESHOLD = 256;

// Insertion sort for small arrays
void insertionSort(int* arr, int start, int end) {
  for (int i = start + 1; i <= end; ++i) {
    int key = arr[i];
    int j = i - 1;
    // Shift elements greater than key to the right
    while (j >= start && arr[j] > key) {
      arr[j + 1] = arr[j];
      --j;
    }
    arr[j + 1] = key;
  }
}

// Median-of-three pivot selection
int medianOfThree(int* arr, int start, int end) {
  int mid = start + (end - start) / 2;
  // Sort first, middle, and end elements
  if (arr[mid] < arr[start]) {
    swap(arr[start], arr[mid]);
  }
  if (arr[end] < arr[start]) {
    swap(arr[start], arr[end]);
  }
  if (arr[end] < arr[mid]) {
    swap(arr[mid], arr[end]);
  }
  // Place median at the end as the pivot
  swap(arr[mid], arr[end]);
  return arr[end];
}

// Partition function using median-of-three pivot selection
int partition(int* arr, int start, int end) {
  // Use the median-of-three method to select the pivot
  int pivot = medianOfThree(arr, start, end);
  int i = start - 1;

  for (int j = start; j < end; ++j) {
    if (arr[j] <= pivot) {
      swap(arr[++i], arr[j]);
    }
  }
  // Place the pivot in the correct position
  swap(arr[i + 1], arr[end]);
  return i + 1;
}

// Optimized QuickSort function
void quickSort(int* arr, int start, int end) {
  while (start < end) {
    // If the range is small, use insertion sort
    if (end - start + 1 <= INSERTION_SORT_THRESHOLD) {
      insertionSort(arr, start, end);
      break;
    }

    // Partition the array and get the pivot index
    int pivotIndex = partition(arr, start, end);

    // Recur to sort the smaller partition first to minimize recursion depth
    if (pivotIndex - start < end - pivotIndex) {
      quickSort(arr, start, pivotIndex - 1);
      start = pivotIndex + 1;
    } else {
      quickSort(arr, pivotIndex + 1, end);
      end = pivotIndex - 1;
    }
  }
}

// Main function
int main() {
  int N;
  cin >> N;

  // Dynamically allocate an array of size N
  int* arr = new int[N];

  // Read N integers into the array
  for (int i = 0; i < N; ++i) {
    cin >> arr[i];
  }

  // Perform the QuickSort
  quickSort(arr, 0, N - 1);

  // Output the sorted array
  for (int i = 0; i < N; ++i) {
    cout << arr[i] << " ";
  }

  // Deallocate the dynamically allocated array
  delete[] arr;

  return 0;
}
