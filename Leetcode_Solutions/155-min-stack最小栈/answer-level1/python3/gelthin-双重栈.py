### 解题思路
用空间换时间，每次入栈时，压入两个元素，第一个元素为当前元素，第二个元素为当前最小的元素。
每次出栈时，也出两个元素。这个思路来自于 [评论区](https://leetcode-cn.com/problems/min-stack/comments/3253)

评论区也有构造数据结构，包含 val 以及 min_val 等方法。
评论区还有搬运 用二叉树来实现最小栈的方法，非常巧妙。

liweiwei [使用辅助栈（同步和不同步，Python 代码、Java 代码）](https://leetcode-cn.com/problems/min-stack/solution/shi-yong-fu-zhu-zhan-tong-bu-he-bu-tong-bu-python-/) 给出了两个栈的思路。其中非同步栈，可以节省一些空间，思路非常好，我大概看懂了。[所谓的单调栈](https://leetcode-cn.com/problems/next-greater-element-i/solution/gelthin-zhe-yi-ge-ti-mu-fei-chang-qiao-miao-by-gel/)




我在评论区[评价](https://leetcode-cn.com/problems/min-stack/solution/shi-yong-fu-zhu-zhan-tong-bu-he-bu-tong-bu-python-/280325)
第二种方法非常巧妙！ 我个人感觉

``` python3
def pop(self):
    # 关键 3：【注意】不论怎么样，数据栈都要 pop 出元素
    top = self.data.pop()

    if self.helper and top == self.helper[-1]:
        self.helper.pop()
    return top
```
这里的 if 语句中 self.helper 似乎是不需要的，如果前面 top 能弹出，那么似乎执行到 if 语句时， self.helper 应该不是空的



### 代码

```python3
class MinStack:  # 用数组来实现栈

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.nums = []   # 每次存入两个数，一个是当前元素，另一个是目前所有元素的最小值

    def push(self, x: int) -> None:
        if self.nums:  # 非空
            min_val = self.nums[-1]
            self.nums.append(x)
            # push min value
            if x < min_val:
                self.nums.append(x)
            else:
                self.nums.append(min_val)
        else:
            self.nums.append(x)
            self.nums.append(x)

    def pop(self) -> None:
        self.nums.pop()
        self.nums.pop()


    def top(self) -> int:
        return self.nums[-2]

    def getMin(self) -> int:
        return self.nums[-1]


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(x)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()
```

### 非同步辅助栈

``` python3
class MinStack:  # 用数组来实现栈

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.nums = []   
        self.helper = [] # 非同步辅助栈  

    def push(self, x: int) -> None:
        self.nums.append(x)
        if not self.helper or x <= self.helper[-1]:  # 相同值也要进去，不然不知道出现了多少次
            self.helper.append(x) 

    def pop(self) -> None:
        top = self.nums.pop()
        if self.helper[-1] == top:
            self.helper.pop()

    def top(self) -> int:
        return self.nums[-1]

    def getMin(self) -> int:
        return self.helper[-1]


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(x)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()
```