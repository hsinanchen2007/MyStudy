### 解题思路

因为列表可长可短，所以可以将长列表的问题分解成较短列表的问题，然后利用递归解决。

按照题目示例，当 K=3 时，写出第一版代码，考虑都列表分解得到的最后一个子数组的长度可能为1/2/3，找出三种情况的最大值即可。

```python3
class Solution:
    def maxSumAfterPartitioning(self, A: List[int], K: int) -> int:
        if len(A) <= K:
            return max(A) * len(A)
        else:
            return max(self.maxSumAfterPartitioning(A[:-1], 3) + max(A[-1:]) * 1
                    self.maxSumAfterPartitioning(A[:-2], 3) + max(A[-2:]) * 2
                    self.maxSumAfterPartitioning(A[:-3], 3) + max(A[-3:]) * 3)

```

第二版代码将 K 从固定值 3 抽象出来，使用 Python 的列表推导找出最大值。

```python3
class Solution:
    def maxSumAfterPartitioning(self, A: List[int], K: int) -> int:
        if len(A) <= K:
            return max(A) * len(A)
        else:
            return max(self.maxSumAfterPartitioning(A[:-k], K) + max(A[-k:]) * k for k in range(1, K+1))

```

通过示例检查结果正确，但是上面的代码执行效率较低，中间会进行很多重复的递归调用。

比如当列表的长度为 10 时，会递归调用列表长度为 9/8/7/6/5... 
当列表的长度为 9 时，会递归调用列表长度为 8/7/6/5...
可以发现很多重复的递归调用

所以加入备忘录，将每一次调用的结果保存，再次调用时查表返回结果。

```python3
class Solution:
    def __init__(self):
        self.memo = {}

    def maxSumAfterPartitioning(self, A: List[int], K: int) -> int:
        if len(A) not in self.memo:
            if len(A) <= K:
                self.memo[len(A)] = max(A) * len(A)
            else:
                self.memo[len(A)] = max(self.maxSumAfterPartitioning(A[:-k], K) + max(A[-k:]) * k for k in range(1, K+1))
        return self.memo[len(A)]
```

至此，就得到最终的代码。

这种分析问题的步骤是通用的，适用于大部分可以分解子问题的题目。