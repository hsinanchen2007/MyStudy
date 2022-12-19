#include <stack>
class MinStack {
public:
  MinStack() { min_.clear(); }
  void push(int x) {
    min_.insert(x);
    real_stack_.push(x);
  }
  void pop() {
    int cur_top = real_stack_.top();
    real_stack_.pop();
    auto min_iter = min_.find(cur_top);
    min_.erase(min_iter);
  }
  int top() { return real_stack_.top(); }
  int getMin() {
    int min = 0;
    if (!min_.empty()) {
      min = *min_.begin();
    }
    return min;
  }

private:
  std::multiset<int> min_;
  std::stack<int> real_stack_;
};