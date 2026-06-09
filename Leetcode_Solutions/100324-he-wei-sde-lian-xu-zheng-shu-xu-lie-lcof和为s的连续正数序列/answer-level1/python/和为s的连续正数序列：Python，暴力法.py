### 解题思路
当存在以i为起点的解时，则不存在以i+1为起点解，可直接以i+2为起点开始搜索，略减少搜索次数。
因为[i+1, n] < [i, n] = target < [i+1, n+1]，所以以i+1为起点不存在解。

### 代码

```python
class Solution(object):
    def findContinuousSequence(self, target):
        """
        :type target: int
        :rtype: List[List[int]]
        """
        rlist = []
        # 第一个数字索引到target/2为止
        i = 1
        while(i <= target/2):
            temp = []
            temp.append(i)
            temp_sum = i
            j = i + 1
            while(temp_sum < target):
                temp.append(j)
                temp_sum += j
                j += 1
            if temp_sum == target:
                rlist.append(temp)
                i = i + 2
            else:
                i += 1
        return rlist
```