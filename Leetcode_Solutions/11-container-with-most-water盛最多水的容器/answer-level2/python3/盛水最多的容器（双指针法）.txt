```
class Solution:
    def maxArea(self, height: List[int]) -> int:
        maxRes = 0
        i = 0
        j = len(height) - 1
        while i < j :
            h = min(height[i], height[j])
            maxRes = max(h * (j - i), maxRes)
            if height[i] < height[j] :  #左边的短
                while i < j and height[i] <= h : i += 1
            else:                       #右边的短
                while i < j and height[j] <= h : j -= 1
        return maxRes
```
最开始，自己只想到了暴力求解，结果果断超时。然后根据官方解答的提示，使用的了双指针法。对于双指针i、j的更新，自己对其作了一个小小的优化（嘿嘿），
比如：height[i] < height[j]，最小值h = height， 计算完之后， 需要修改i值，此时在确定i值的时候会去直接找到那个新的i，其一定会满足height[i] > h， 这样算出来的面积才有可能大于之前的那个。
通过这种方法，减少了面积的计算次数，在时间上可以减少一些。