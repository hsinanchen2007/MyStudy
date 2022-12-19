### 解题思路
一开始自己用的暴力破解，奈何用Python时间通过不了。
看了大神们的解法，发现滑动窗口厉害极了！
需要注意的是，滑动窗口在滑动的时候，始终是左闭右开。所以append的时候是range(i,j)。也就是说，j总是超前一步的。
还有数学的方法，也很值得学习！

### 代码

```python
class Solution(object):
    def findContinuousSequence(self, target):
        """
        :type target: int
        :rtype: List[List[int]]
        """
        m = int((target+1)/2)
        i = 1
        j = 1
        result = []
        s = 0
        while i < m:
            #print(i,j,s)
            if s < target:
                s += j
                j += 1
            elif s > target:
                s -= i
                i += 1
            else:
                result.append(range(i,j))
                s += j
                j += 1
        return result

```