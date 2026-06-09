**思路：**

动态规划。我们用数组`stock`代表每天股票的价格，直接遍历不是最好的方法，在第`i`次调用函数`next`的时候，我们考虑第`i-1`天的股票价格：若第`i-1`天股票价格大于第`i`天，我们应该返回答案`1`；若第`i-1`天的股票价格小于等于第`i`天，那么第`i-1`天左边连续小于等于`i-1`天的股票价格显然也小于等于第`i`天的股票价格，如果我们用`spanner`数组表示每次`next`函数输出的结果，那么我们只需要从第`i-1`天开始，跳过`spanner[i-1]`天，再继续检查第`i-spanner[i-1]`天的股票价格即可。

这个过程也可以用单调栈实现，这道题的本质是寻找每个数左边第一个比它严格大的数字，故可以采用单调栈的思想，维护一个单调递减的栈，栈中存放数字的下标，每次新加入一个数字时，若栈顶小于等于当前数字，则出栈直到栈空或者栈顶严格大于当前数字，最终栈顶距离新插入数字的下标的距离就是答案，然后将新数字压栈。

代码还可以进一步优化，当第`i`次调用`next`函数的时候，前`i-1`天小于第`i`天的股票价格就没必要保存了，我们直接在单调栈中，既保存股票价格又保存股票价格的时间跨度即可。

时间复杂度$O(N)$

空间复杂度$O(N)$

**图解：**

![图解](https://pic.leetcode-cn.com/c6482e40aa3916dcc994298a419f1f7c7ddc051e7bc0c26543dd088e62eaef07.gif)

**代码：**

```python
class StockSpanner:
    
    def __init__(self):
        self.stock = []
        self.spanner = []
        self.length = 0

    def next(self, price):
        """
        :type price: int
        :rtype: int
        """
        ans = 1
        i = self.length - 1
        while i >= 0 and self.stock[i] <= price:
            ans += self.spanner[i]
            i -= self.spanner[i]
            
        self.length += 1
        self.stock.append(price)
        self.spanner.append(ans)
        
        return ans


# Your StockSpanner object will be instantiated and called as such:
# obj = StockSpanner()
# param_1 = obj.next(price)
```

单调栈实现

```python
class StockSpanner:

    def __init__(self):
        self.stock = []
        self.stack = []
        self.length = 0

    def next(self, price):
        """
        :type price: int
        :rtype: int
        """
        ans = 0
        while self.stack and self.stock[self.stack[-1]] <= price:
            self.stack.pop()
        
        if not self.stack:
            ans = self.length + 1
        else:
            ans = self.length - self.stack[-1]
        self.stock.append(price)
        self.stack.append(self.length)
        
        self.length += 1
        
        return ans


# Your StockSpanner object will be instantiated and called as such:
# obj = StockSpanner()
# param_1 = obj.next(price)
```

进一步优化

```python
class StockSpanner(object):

    def __init__(self):
        self.stack = []

    def next(self, price):
        """
        :type price: int
        :rtype: int
        """
        ans = 1
        while self.stack and self.stack[-1][0] <= price:
            ans += self.stack.pop()[1]
        self.stack.append((price, ans))
        return ans

# Your StockSpanner object will be instantiated and called as such:
# obj = StockSpanner()
# param_1 = obj.next(price)
```