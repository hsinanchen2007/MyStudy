### 解题思路
c++ 
执行用时 :
0 ms
, 在所有 C++ 提交中击败了
100.00%
的用户
内存消耗 :
7 MB
, 在所有 C++ 提交中击败了
100.00%
的用户
可用用一个queue 维护也可以用两个

### 代码

```cpp
class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {

    }
    
    /** Push element x onto stack. */
    void push(int x) {
        if (fir_queue_.empty() && sec_queue_.empty()) {
            fir_queue_.push(x);
        } else if (fir_queue_.empty() && !sec_queue_.empty()) {
            sec_queue_.push(x);
        } else if (!fir_queue_.empty() && sec_queue_.empty()) {
            fir_queue_.push(x);
        } else {
        return;
        }
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        auto last_ele = -1;
    if (!fir_queue_.empty() && sec_queue_.empty()) {
        //std::cout << "asdasd" << std::endl;
      last_ele = DealTwoqueue(fir_queue_, sec_queue_);
      return last_ele;
    }
    if (fir_queue_.empty() && !sec_queue_.empty()) {
        //std::cout << "asdasdqweqwe" << std::endl;
      last_ele = DealTwoqueue(sec_queue_, fir_queue_);
      return last_ele;
    }
    return last_ele;
    }

    /** Get the top element. */
    int top() {
        auto last_ele = -1;
    if (!fir_queue_.empty() && sec_queue_.empty()) {
      last_ele = ScanTwoqueue(fir_queue_, sec_queue_);
      return last_ele;
    }
    if (fir_queue_.empty() && !sec_queue_.empty()) {
      last_ele = ScanTwoqueue(sec_queue_, fir_queue_);
      return last_ele;
    }
    return last_ele;
    }

    /** Returns whether the stack is empty. */
    bool empty() { return (fir_queue_.empty() && sec_queue_.empty()); }
    private:
    int DealTwoqueue(std::queue<int> &src_queue, std::queue<int> &dst_queue) {
        if (!src_queue.empty() && dst_queue.empty()) {
            auto ori_size = src_queue.size();
            auto i = ori_size;
            while (i > 1) {
                auto curr_ele = src_queue.front();
                dst_queue.push(curr_ele);
                src_queue.pop();
                --i;
            }
            auto last_ele = src_queue.front();
            //std::cout << "las deal" << last_ele << std::endl;
            src_queue.pop();
        return last_ele;
    }
    return -1;
    }
    int ScanTwoqueue(std::queue<int> &src_queue, std::queue<int> &dst_queue) {
        if (!src_queue.empty() && dst_queue.empty()) {
            auto ori_size = src_queue.size();
            auto i = ori_size;
            while (i > 1) {
                auto curr_ele = src_queue.front();
                dst_queue.push(curr_ele);
                src_queue.pop();
                --i;
            }
        auto last_ele = src_queue.front();
        dst_queue.push(last_ele);
        //std::cout << "las scan" << last_ele << std::endl;
        src_queue.pop();
        return last_ele;
    }
    return -1;
    }
    private:
    std::queue<int> fir_queue_;
    std::queue<int> sec_queue_;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
```