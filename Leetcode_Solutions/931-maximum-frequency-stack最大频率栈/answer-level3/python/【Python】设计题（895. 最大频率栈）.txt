## 题目地址（895. 最大频率栈）

https://leetcode-cn.com/problems/maximum-frequency-stack/

## 题目描述

```
实现 FreqStack，模拟类似栈的数据结构的操作的一个类。

FreqStack 有两个函数：

push(int x)，将整数 x 推入栈中。
pop()，它移除并返回栈中出现最频繁的元素。
如果最频繁的元素不只一个，则移除并返回最接近栈顶的元素。
 

示例：

输入：
["FreqStack","push","push","push","push","push","push","pop","pop","pop","pop"],
[[],[5],[7],[5],[7],[4],[5],[],[],[],[]]
输出：[null,null,null,null,null,null,null,5,7,5,4]
解释：
执行六次 .push 操作后，栈自底向上为 [5,7,5,7,4,5]。然后：

pop() -> 返回 5，因为 5 是出现频率最高的。
栈变成 [5,7,5,7,4]。

pop() -> 返回 7，因为 5 和 7 都是频率最高的，但 7 最接近栈顶。
栈变成 [5,7,5,4]。

pop() -> 返回 5 。
栈变成 [5,7,4]。

pop() -> 返回 4 。
栈变成 [5,7]。
 

提示：

对 FreqStack.push(int x) 的调用中 0 <= x <= 10^9。
如果栈的元素数目为零，则保证不会调用  FreqStack.pop()。
单个测试样例中，对 FreqStack.push 的总调用次数不会超过 10000。
单个测试样例中，对 FreqStack.pop 的总调用次数不会超过 10000。
所有测试样例中，对 FreqStack.push 和 FreqStack.pop 的总调用次数不会超过 150000。

```

## 思路

我们以题目给的例子来讲解。

- 使用fraq 来存储对应的数字出现次数。key 是数字，value频率

![](https://pic.leetcode-cn.com/5823da675060e1d1725c2cb0f5d4f0cd68870c2599914eb7c28c2fa56c38d61b.jpg)

- 由于题目限制“如果最频繁的元素不只一个，则移除并返回最接近栈顶的元素。”，我们考虑使用栈来维护一个频率表 fraq_stack。key是频率，value是数字组成的栈。

![](https://pic.leetcode-cn.com/8c5d16af06b2bbf15ac75dad30898e99c0b19b83d433b303a4f0fb8ac885387b.jpg)

- 同时用max_fraq 记录当前的最大频率值。

- 第一次pop的时候，我们最大的频率是3。由fraq_stack 知道我们需要pop掉5。

![](https://pic.leetcode-cn.com/e48a3ca56afbfe6994488411c2a84887add5944a39c55196218d29814ee2e544.jpg)

- 之后pop依次是这样的（红色数字表示顺序）

![](https://pic.leetcode-cn.com/5bb2217c2b4d870f7e1969528d7dd4d9f92eed6345572c96f2cf4d094729b56c.jpg)

## 关键点解析

- 栈的基本性质
- hashtable的基本性质
- push和pop的时候同时更新fraq，max_fraq 和 fraq_stack。

## 代码

```python
class FreqStack:

    def __init__(self):
        self.fraq = collections.defaultdict(lambda: 0)
        self.fraq_stack = collections.defaultdict(list)
        self.max_fraq = 0
        
    def push(self, x: int) -> None:
        self.fraq[x] += 1
        if self.fraq[x] > self.max_fraq:
            self.max_fraq = self.fraq[x]
        self.fraq_stack[self.fraq[x]].append(x)    
        
    def pop(self) -> int:
        ans = self.fraq_stack[self.max_fraq].pop()
        self.fraq[ans] -= 1
        if not self.fraq_stack[self.max_fraq]:
            self.max_fraq -= 1
        return ans

# Your FreqStack object will be instantiated and called as such:
# obj = FreqStack()
# obj.push(x)
# param_2 = obj.pop()
```

***复杂度分析***
- 时间复杂度：push 和 pop 平均时间复杂度是 $O(1)$
- 空间复杂度：$O(N)$，其中N为数字的总数。

更多题解可以访问我的LeetCode题解仓库：https://github.com/azl397985856/leetcode  。 目前已经接近30K star啦。

大家也可以关注我的公众号《脑洞前端》获取更多更新鲜的LeetCode题解

![](https://pic.leetcode-cn.com/89ef69abbf02a2957838499a96ce3fbb26830aae52e3ab90392e328c2670cddc-file_1581478989502)


