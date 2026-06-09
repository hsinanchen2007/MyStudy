## 代码

```cpp
class CustomStack {
private:
    vector<int> vec;
    int size_ = 0; // 记录当前栈的大小
public:
    CustomStack(int maxSize) : vec(maxSize) {
    }
    
    void push(int x) {
        if (size_ < vec.size()) // 当还有剩余空间时压栈
            vec[size_++] = x;
    }
    
    int pop() {
        if (size_ > 0) // 当栈内有剩余元素时出栈
            return vec[--size_];
        else
            return -1;
    }
    
    void increment(int k, int val) { // 暴力刷新值
        for (int i = 0; i < k && i < size_; i++)
            vec[i] += val;
    }
};

```

## 效率改进

```cpp
class CustomStack {
private:
    vector<int> vec;
    vector<int> delta; // 记录增量值
    int size_ = 0;
public:
    CustomStack(int maxSize) : vec(maxSize), delta(maxSize) {
    }
    
    void push(int x) {
        if (size_ < vec.size()) {
            delta[size_] = 0;
            vec[size_++] = x;
        }
    }
    
    int pop() {
        if (size_ > 0) {
            size_--;
            if (size_ > 0)
                delta[size_ - 1] += delta[size_]; // 增量值累加到栈里面的下一个值
            return vec[size_] + delta[size_]; // 元素出栈时要加上对应的增量
        } else
            return -1;
    }
    
    void increment(int k, int val) {
        if (k > size_)
            k = size_;
        if (k > 0)
            delta[k - 1] += val; // 记录增量值
    }
};
```