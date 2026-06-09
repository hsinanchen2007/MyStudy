### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    """
    问题分析：
        题目要求连续的数组，连续二字就表明可以使用滑动窗口，滑动窗口需要双指针．因此解法确定为＂滑动窗口+双指针＂
    思路：
        由于是正整数数组，因此可以先找到最大长度的数组，再瘦身．遍历完数组之后找到长度最小的那个
    @temp: 中间结果和
    @res:　数组长度
    @left: 　滑动窗口左指针
    ＠right:　滑动窗口右指针
    """
    def minSubArrayLen(self, s: int, nums: List[int]) -> int:
        if sum(nums) < s:
            return 0
            
        length = len(nums)
        left = 0
        temp = 0
        res = float('inf')

        for right in range(length):
            temp += nums[right]
            #滑动窗口瘦身
            while temp >= s:
                res = min(res, right-left + 1)
                temp -= nums[left]
                left += 1

        return res
```