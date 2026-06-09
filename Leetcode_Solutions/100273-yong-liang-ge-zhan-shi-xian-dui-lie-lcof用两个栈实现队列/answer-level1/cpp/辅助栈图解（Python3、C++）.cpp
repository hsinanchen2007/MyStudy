### 解题思路

只使用一个栈 `stack1` 当作队列，另一个栈 `stack2` 用来辅助操作。

要想将新加入的元素出现栈底，需要先将 `stack1` 的元素转移到 `stack2`，将元素入栈 `stack1`，最后将 `stack2` 的元素全部回到 `stack1`。

![09.gif](https://pic.leetcode-cn.com/966aebd484002e620d88676847273a061ab9ab6d863ab5079ab347a643461e24-09.gif)


### 代码

```python []
class CQueue:

    def __init__(self):
        self.stack1 = []
        self.stack2 = []

    def appendTail(self, value: int) -> None:
        # 1 -> 2
        while self.stack1:
            self.stack2.append(self.stack1.pop())
        # add value
        self.stack1.append(value)
        # 1 <- 2
        while self.stack2:
            self.stack1.append(self.stack2.pop())
        return self.stack1

    def deleteHead(self) -> int:
        if not self.stack1: return -1
        return self.stack1.pop()
```
```cpp []
class CQueue {
public:
    stack<int> stack1;
    stack<int> stack2;
    CQueue() {}
    
    void appendTail(int value) {
        stack1.push(value);
    }
    
    int deleteHead() {
        if (stack1.empty()) return -1;
        
        while (!stack1.empty()){ // 1 -> 2
            int tmp = stack1.top();
            stack1.pop();
            stack2.push(tmp);
        }
        // delete head
        int res = stack2.top();
        stack2.pop();
        while (!stack2.empty()){ // 1 <- 2
            int temp = stack2.top();
            stack2.pop();
            stack1.push(temp);
        }
        return res;
    }
};

```


### 复杂度分析
**1. 插入**

- 时间复杂度：$O(n)$。
- 空间复杂度：$O(n)$，使用了辅助栈的空间。

**2. 删除**

- 时间复杂度：$O(1)$。
- 空间复杂度：$O(1)$，`stack1` 当作了队列，直接在原队列上删除，没使用额外空间。

