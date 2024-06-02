#include <iostream>
#include <stack>

class SortingHat {
 private:
  std::stack<long> inStack;
  std::stack<long> outStack;
  std::stack<long> minInStack;
  std::stack<long> minOutStack;

  void transferToOutStack() {
    while (!inStack.empty()) {
      long value = inStack.top();
      inStack.pop();

      if (minOutStack.empty() || value <= minOutStack.top()) {
        minOutStack.push(value);
      } else {
        minOutStack.push(minOutStack.top());
      }

      outStack.push(value);
    }
    // Clear the minInStack when all elements are transferred to outStack
    while (!minInStack.empty()) {
      minInStack.pop();
    }
  }

 public:
  void enqueue(long n) {
    inStack.push(n);
    // Maintain the minimum stack for inStack
    if (minInStack.empty() || n <= minInStack.top()) {
      minInStack.push(n);
    } else {
      minInStack.push(minInStack.top());
    }
    std::cout << "ok" << std::endl;
  }

  void dequeue() {
    if (outStack.empty()) {
      transferToOutStack();
    }

    if (outStack.empty()) {
      std::cout << "error" << std::endl;
    } else {
      long value = outStack.top();
      outStack.pop();
      minOutStack.pop();
      std::cout << value << std::endl;
    }
  }

  void front() {
    if (outStack.empty()) {
      transferToOutStack();
    }

    if (outStack.empty()) {
      std::cout << "error" << std::endl;
    } else {
      std::cout << outStack.top() << std::endl;
    }
  }

  void size() { std::cout << inStack.size() + outStack.size() << std::endl; }

  void clear() {
    while (!inStack.empty()) {
      inStack.pop();
    }
    while (!outStack.empty()) {
      outStack.pop();
    }
    while (!minInStack.empty()) {
      minInStack.pop();
    }
    while (!minOutStack.empty()) {
      minOutStack.pop();
    }
    std::cout << "ok" << std::endl;
  }

  void min() {
    if (inStack.empty() && outStack.empty()) {
      std::cout << "error" << std::endl;
    } else {
      long minValue = 1000000001;  // Use 1000000001 as an initial large value
                                   // for comparison

      if (!minInStack.empty()) {
        minValue = std::min(minValue, minInStack.top());
      }

      if (!minOutStack.empty()) {
        minValue = std::min(minValue, minOutStack.top());
      }

      std::cout << minValue << std::endl;
    }
  }
};

int main() {
  int M;
  std::cin >> M;

  SortingHat hat;

  std::string command;
  long n;

  for (int i = 0; i < M; ++i) {
    std::cin >> command;
    if (command == "enqueue") {
      std::cin >> n;
      hat.enqueue(n);
    } else if (command == "dequeue") {
      hat.dequeue();
    } else if (command == "front") {
      hat.front();
    } else if (command == "size") {
      hat.size();
    } else if (command == "clear") {
      hat.clear();
    } else if (command == "min") {
      hat.min();
    }
  }

  return 0;
}
