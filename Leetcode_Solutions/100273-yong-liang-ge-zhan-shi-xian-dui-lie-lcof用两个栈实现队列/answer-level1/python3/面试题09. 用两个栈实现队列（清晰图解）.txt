#### 解题思路：

- **栈无法实现队列功能：** 栈底元素（对应队首元素）无法直接删除，需要将上方所有元素出栈。
- **双栈可实现列表倒序：** 设有含三个元素的栈 $A = [1,2,3]$ 和空栈 $B = []$。若循环执行 $A$ 元素出栈并添加入栈 $B$ ，直到栈 $A$ 为空，则 $A = []$ , $B = [3,2,1]$ ，即 **栈 $B$ 元素实现栈 $A$ 元素倒序** 。
- **利用栈 $B$ 删除队首元素：** 倒序后，$B$ 执行出栈则相当于删除了 $A$ 的栈底元素，即对应队首元素。

![Picture0.png](https://pic.leetcode-cn.com/b813bda09374058f18449b18cc6536a5b8670d5a7b65867eb65b32066c79c1ae-Picture0.png){:width=500}

##### 函数设计：

> 题目只要求实现 **加入队尾**`appendTail()` 和 **删除队首**`deleteHead()` 两个函数的正常工作，因此我们可以设计栈 `A` 用于加入队尾操作，栈 `B` 用于将元素倒序，从而实现删除队首元素。

- **加入队尾 `appendTail()`函数：** 将数字 `val` 加入栈 `A` 即可。
- **删除队首`deleteHead()`函数：** 有以下三种情况。
    1. **当栈 `B` 不为空：** `B`中仍有已完成倒序的元素，因此直接返回 `B` 的栈顶元素。
    2. **否则，当 `A` 为空：** 即两个栈都为空，无元素，因此返回 $-1$ 。
    3. **否则：** 将栈 `A` 元素全部转移至栈 `B` 中，实现元素倒序，并返回栈 `B` 的栈顶元素。

<![Picture1.png](https://pic.leetcode-cn.com/ff3c5e71e479e64fc0a1cc07cb653e50da3ab614e920b39c8122c173d092ba19-Picture1.png),![Picture2.png](https://pic.leetcode-cn.com/77c5b8da759d243c7f4a19608483eef6eea4979d89e21a969d0dc6f017266be3-Picture2.png),![Picture3.png](https://pic.leetcode-cn.com/d7b6c80bdcbbc293f77ed3ba0faa1e58914def046f8e013c7bb24431611e3d23-Picture3.png),![Picture4.png](https://pic.leetcode-cn.com/20c76486e1cefc96b05d25e4b61ae685f8b3e33599bf4aabdc95a757fca33aa0-Picture4.png),![Picture5.png](https://pic.leetcode-cn.com/f937cdc432c8b835f626a4ad6a4bf3307d1e90b77c39d8b5426e6f6016c16360-Picture5.png),![Picture6.png](https://pic.leetcode-cn.com/95bcb4872f80596a74a5331c4658e388599e62d24c0e86c70673835e7747e87e-Picture6.png),![Picture7.png](https://pic.leetcode-cn.com/e57162b03d995cc8e550895ca2d08856f8f3035e24cf293219e232791eec468e-Picture7.png),![Picture8.png](https://pic.leetcode-cn.com/8401a33b62a40cefb1cd25712ae6c3fe49c8f7f5bfe77fa154675ea615b12ade-Picture8.png)>

##### 复杂度分析：

> 由于问题特殊，以下分析仅满足添加 $N$ 个元素并删除 $N$ 个元素，即栈初始和结束状态下都为空的情况。

- **时间复杂度：** `appendTail()`函数为 $O(1)$ ；`deleteHead()` 函数在 $N$ 次队首元素删除操作中总共需完成 $N$ 个元素的倒序。
- **空间复杂度 $O(N)$ ：** 最差情况下，栈 `A` 和 `B` 共保存 $N$ 个元素。

#### 代码：

```python []
class CQueue:
    def __init__(self):
        self.A, self.B = [], []

    def appendTail(self, value: int) -> None:
        self.A.append(value)

    def deleteHead(self) -> int:
        if self.B: return self.B.pop()
        if not self.A: return -1
        while self.A:
            self.B.append(self.A.pop())
        return self.B.pop()
```

```java []
class CQueue {
    LinkedList<Integer> A, B;
    public CQueue() {
        A = new LinkedList<Integer>();
        B = new LinkedList<Integer>();
    }
    public void appendTail(int value) {
        A.addLast(value);
    }
    public int deleteHead() {
        if(!B.isEmpty()) return B.removeLast();
        if(A.isEmpty()) return -1;
        while(!A.isEmpty())
            B.addLast(A.removeLast());
        return B.removeLast();
    }
}
```