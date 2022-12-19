### 解题思路
使用C++的STL中的std::deque容器可以模拟实现栈操作。

### 代码

```cpp
MyStack() {}

void push(int x) {
    // 从队列尾入队模拟压栈
    deq.push_back(x);
}

int pop() {
    // 先从队列尾取最后一个数
    int p = deq.back();
    // 再从队列尾出队模拟出栈
    deq.pop_back();

    return p;
}

int top() {
    // 从队列尾取数模拟获取栈顶元素
    return deq.back();
}

bool empty() {
    // 判断队列为空模拟判断栈为空
    return deq.empty();
}
```