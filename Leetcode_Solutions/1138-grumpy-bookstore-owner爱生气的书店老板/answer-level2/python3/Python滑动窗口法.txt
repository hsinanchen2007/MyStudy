本题可将结果分为两部分：
1）所有grumpy等于0的区域进行求和，作为base
2）寻找一个长度为X的窗口，使得窗口中grumpy为1积累的新用户最多，作为delta。
结果即为base+delta。

```python
class Solution(object):
    def maxSatisfied(self, customers, grumpy, X):
        """
        :type customers: List[int]
        :type grumpy: List[int]
        :type X: int
        :rtype: int
        """
        N = len(customers)
        tmp = sum_ = 0
        for i in range(N):
            if not grumpy[i]:        
                sum_ += customers[i]
            if i < X and grumpy[i]:
                tmp += customers[i]   
        res = tmp
        for i in range(1, N-X+1):
            print(i,res)
            pre, pos = i-1, i+X-1 
            if grumpy[pre]:
                tmp -= customers[pre]
            if grumpy[pos]:
                tmp += customers[pos]
            res = max(tmp, res)
        return res + sum_
```