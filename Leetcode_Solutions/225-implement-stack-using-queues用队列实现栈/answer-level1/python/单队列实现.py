### 解题思路 ###
#### 步骤 ####
##### 压入 #####
1. 每次将新元素压入队尾之前，记录队列的当前长度`size`，然后将新元素压入队尾
2. 将队首元素弹出，压入队尾，循环`size`次，保证新元素在队首

<![225.1.png](https://pic.leetcode-cn.com/66ca64047978589564b3a7121d694442c9375efbe1f9d8b5fb57f33ad2c23d2b-225.1.png),![225.2.png](https://pic.leetcode-cn.com/4b33ee4f4f8db7f9a3f51b8c79cf6a67d6a32fdfcac7cb1b9ecd4397cf7e8565-225.2.png),![225.3.png](https://pic.leetcode-cn.com/a876326ebb4775b3df300e2b2af904503d4ee69f9d6efbc6d241291cfd4d376f-225.3.png),![225.4.png](https://pic.leetcode-cn.com/e00703de6d419068bd70eed303a061c6c5e04a9a97a58f5db36391ba89bd766a-225.4.png),![225.5.png](https://pic.leetcode-cn.com/1b91422891227192751cf05e3c6e26ff0559a6588d94c200ba3ff643ff68f192-225.5.png)>

##### 弹出 #####
- 弹出队首元素并返回即可
#### 复杂度分析 ####
- 压入操作要执行`size`次循环，故时间复杂度为`O(n)`
- 弹出操作时间复杂度为`O(1)`
<br/>
***
### 代码 ###
<br/>
```c++ []
class MyStack {
private:
    queue<int> q;
public:
    void push(int x) {
        int size = q.size();
        q.push(x);
        while (size--) {
            q.push(q.front());
            q.pop();
        }
    }
    int pop() {
        int res = q.front();
        q.pop();
        return res;
    }
    int top() {
        return q.front();
    }
    bool empty() {
        return q.empty();
    }
};
```
```python []
class MyStack(object):

    def __init__(self):
        self.queue = collections.deque()

    def push(self, x):
        size = len(self.queue)
        self.queue.append(x)
        for i in range(size):
            self.queue.append(self.queue.popleft())

    def pop(self):
        return self.queue.popleft()

    def top(self):
        return self.queue[0]

    def empty(self):
        return not bool(self.queue)
```
```python []
class MyStack(collections.deque):

    def push(self, x: int) -> None:
        self.append(x)
        for _ in range(len(self) - 1):
            self.append(self.popleft())

    def pop(self) -> int:
        return self.popleft()

    def top(self) -> int:
        return self[0]

    def empty(self) -> bool:
        return not bool(self)
```

