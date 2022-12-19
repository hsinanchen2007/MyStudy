### 双栈法 ###
#### 思路 ####
- 在进行增量操作时，将所有元素从数据栈中弹出，压入辅助栈
- 随后，将所有元素从辅助栈中弹出，压入数据栈
  - 每次压入后，若栈顶元素是前 $k$ 个从辅助栈弹出的元素，增加 $val$
#### 代码 ####
```cpp []
class CustomStack {
public:
    int maxSize;
    stack<int> data, helper;

    CustomStack(int maxSize) : maxSize(maxSize) {}
    
    void push(int x) {
        if (data.size() == maxSize) return;
        data.push(x);
    }
    
    int pop() {
        if (data.empty()) return -1;
        int res = data.top(); data.pop();
        return res;
    }
    
    void increment(int k, int val) {
        while (!data.empty()) {
            helper.push(data.top());
            data.pop();
        }
        while (!helper.empty()) {
            data.push(helper.top());
            helper.pop();
            if (k-- > 0) data.top() += val;
        }
    }
};
```
```python3 []
class CustomStack:

    def __init__(self, maxSize: int):
        self.maxSize = maxSize
        self.data, self.helper = collections.deque(), collections.deque()

    def push(self, x: int) -> None:
        if len(self.data) == self.maxSize: return
        self.data.append(x)

    def pop(self) -> int:
        return self.data.pop() if self.data else -1

    def increment(self, k: int, val: int) -> None:
        while self.data:
            self.helper.append(self.data.pop())
        while self.helper:
            self.data.append(self.helper.pop())
            if k > 0:
                self.data[-1] += val
                k -= 1
```
