### 解题思路
![image.png](https://pic.leetcode-cn.com/954f088661062b42d7c843e6f8183741b39a06156781c67abcd892ec8948f00a-image.png)

- 这个题还是像57题那样,设置两个指针来求解
- 这次的两个指针初始化为`low=1,high=2`,设置变量`cur_sum`来记录当前阶段的总和,初始为`cur_sum=3`
- 当`cur_sum == target`时,直接存储`low`到`high`之间的数字,接着寻找下个符合条件的数组,`high += 1`,`cur_sum += high`,注意这两部不能颠倒位置,下同
- 当`cur_sum < target`时,不符合条件,接着寻找下个符合条件的数组,`high += 1`,`cur_sum += high`
- 当`cur_sum > target`时,不符合条件,接着寻找下个符合条件的数组,`cur_sum -= low`,`low += 1`
- 时间复杂度`O(n)`,空间复杂度`O(1)`
### 代码

```python
class Solution(object):
    def findContinuousSequence(self, target):
        """
        :type target: int
        :rtype: List[List[int]]
        """
        if target <= 2:
            return []
        
        low = 1
        high = 2
        cur_sum = 3
        result = []
        while high <= target / 2 + 1:
            if cur_sum == target:
                result.append([i for i in range(low, high+1)])
                high += 1
                cur_sum += high
            elif cur_sum < target:
                high += 1
                cur_sum += high
            else:
                cur_sum -= low
                low += 1
        return result


            



```