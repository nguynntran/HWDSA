#include <iostream>
#include <stack>
#include <vector>

template <typename T>
int binarySearch(std::vector<T>& a, int s, int e, T k) {
  if (e <= s) {
    return (a[s] > k) ? s : s + 1;
  }
  int m = (e + s) / 2;
  if (a[m] == k) {
    return m + 1;
  } else if (a[m] < k) {
    return binarySearch(a, m + 1, e, k);
  } else {
    return binarySearch(a, s, m, k);
  }
}

template <typename T>
void insertionSort(std::vector<T>& a, int s, int e) {
  for (int i = s + 1; i < e; i++) {
    T k = a[i];
    int j = i - 1;
    int p = binarySearch<T>(a, s, j, k);
    for (; j >= p; j--) {
      a[j + 1] = a[j];
    }
    a[p] = k;
  }
}

template <typename T>
T selectFive(std::vector<T> a, int l, int r) {
  if (r - l + 1 <= 5) {
    insertionSort(a, l, r + 1);
    return a[(r + l) / 2];
  }
  std::vector<T> m;
  for (int i = l; i <= r; i += 5) {
    if (i + 5 > r) {
      insertionSort(a, i, r + 1);
      m.push_back(a[(i + r) / 2]);
      break;
    }
    insertionSort(a, i, i + 5);
    m.push_back(a[(i + i + 4) / 2]);
  }
  return selectFive(m, 0, m.size() - 1);
}

template <typename T>
int partitionPoint(std::vector<T>& a, int l, int r, T m) {
  while (l <= r) {
    for (; a[l] < m; ++l) {
    }
    for (; a[r] > m; --r) {
    }
    if (l >= r) {
      break;
    }
    std::swap(a[l++], a[r--]);
  }
  return r;
}

template <typename T>
void QuickSort(std::vector<T>& a) {
  int s = a.size();
  if (s <= 256) {
    insertionSort(a, 0, s);
    return;
  }
  std::stack<std::pair<int, int>> i_s;
  i_s.emplace(0, s - 1);
  while (!i_s.empty()) {
    int l = i_s.top().first;
    int r = i_s.top().second;
    i_s.pop();
    if (r <= l) {
      continue;
    }
    T p = selectFive(a, l, r);
    int pi = partitionPoint(a, l, r, p);
    if (pi - l + 1 <= 100) {
      insertionSort(a, l, pi + 1);
    } else {
      i_s.emplace(l, pi + 1);
    }
    if (r - pi + 1 < 100) {
      insertionSort(a, pi + 1, r + 1);
    } else {
      i_s.emplace(pi + 1, r);
    }
  }
}

int main() {
  int s;
  long long ph;
  std::cin >> s;
  std::vector<long long> a;
  for (int i = 0; i < s; i++) {
    std::cin >> ph;
    a.push_back(ph);
  }
  QuickSort<long long>(a);
  for (int i = 0; i < s; i++) {
    if (i != s - 1) {
      std::cout << a[i] << ' ';
    } else {
      std::cout << a[i] << '\n';
    }
  }
  return 0;
}
