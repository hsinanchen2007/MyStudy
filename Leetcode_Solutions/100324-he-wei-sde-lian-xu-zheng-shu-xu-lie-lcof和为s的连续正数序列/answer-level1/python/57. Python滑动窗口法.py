### 解题思路
这道题比较常见的解法有三种：
（1）两层循环遍历
（2）数学方法：连续正整数序列是等差序列可以用求和公式计算另一个端点值是否是整数。
（3）滑动窗口法：维护两个指针（并不需要数组，因为data[i] == i没有实际创建的必要），根据窗口内的和与target的大小关系进行指针移动，具体移动策略可以参照下面代码。

### 代码

```python
class Solution(object):
    def findContinuousSequence(self, target):
        """
        :type target: int
        :rtype: List[List[int]]
        """
        p, q = 1, 2
        sum = 3
        res = []
        while p < q and q < target: # q == target 不可能是解，因为至少含有两个数
            if sum < target:
                q += 1
                sum += q
            elif sum > target:
                sum -= p
                p += 1
            else:
                res.append([i for i in range(p, q + 1)])
                sum -= p
                p += 1
        return res

```