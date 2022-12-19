### 解题思路
首先我们考虑一个简单的情况，如果老板每时每刻都在生气，那我们应该怎么做？这时候题目就变成了，长度为X的连续子序列最大值是多少。这时候很容易想到O(n)的解决方法，即像滑动窗口一样，每次删除头，加上尾巴，找出最大值即可。
对于增加了grumpy数组的情况同理，只需要在删除头，增加尾巴的时候乘以grumpy对应的值即可。

### 代码

```python
class Solution(object):
    def maxSatisfied(self, customers, grumpy, X):
        """
        :type customers: List[int]
        :type grumpy: List[int]
        :type X: int
        :rtype: int
        """
        if X >= len(customers):
            return sum(customers)
        temp = 0
        first = customers[0] * grumpy[0]
        for i in range(X):
            temp += customers[i] * grumpy[i]
        tempp = temp
        for j in range(X, len(customers)):
            tempp = tempp - first + customers[j] * grumpy[j]
            first = customers[j-X+1] * grumpy[j-X+1]
            temp = max(temp, tempp)
        sum_temp = 0
        for k in range(len(customers)):
            sum_temp += customers[k] * grumpy[k]
        return sum(customers)-sum_temp+temp
            
```