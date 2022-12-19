### 解题思路
1. 题意很好理解，但是自己还是理解偏了，或者说没有落实到纸面上，导致注释中错误的代码，运行错误：只要相邻元素不递增: 1 8 2 7 15
2. 深入理解题意：子数组A的max 和 min 要满足，min 不小于nums[:l], max 不大于nums[r:]，暴力求解 > O(NN)，暂时忽略
3. **copy 快排：**【1】中的“相邻”法启发，对原数组进行copy排序即可，提交OK，time 打败53%，**时间 复杂图O(NlgN)**
4. 最终看题解中的官方 还算比较满意，但是也比较吃惊，**竟然有O(N)的解法，四次遍历**
    - 这个算法背后的思想是无序子数组中：**最小元素和最大元素的正确位置可确定边界**。最小元素的正确位置可以决定左边界，最大元素的正确位置可以决定右边界
    - 前两次查找最小元素以及最小元素正确排位的位置p
    - 后两次查找最大元素以及最大元素正确排位的位置q 
### 代码

```python3
class Solution:
    def findUnsortedSubarray(self, nums: List[int]) -> int:
        '''
        l = 0
        h = len(nums) - 1
        if h < 1:
            return 0
        l += 1
        while l <= h:
            if nums[l] < nums[l-1]:
                break
            l += 1
        while l < h:
            if nums[h] < nums[h-1]:
                break
            h -= 1
        return h -l + 1
        '''
        l = 0
        h = len(nums) - 1
        if h < 1:
            return 0

        s_nums = sorted(nums)
        while l < h:
            if s_nums[l] != nums[l]:
                break
            l += 1
        while l < h:
            if s_nums[h] != nums[h]:
                break
            h -= 1
        if l == h:
            return 0
        return h - l + 1





```