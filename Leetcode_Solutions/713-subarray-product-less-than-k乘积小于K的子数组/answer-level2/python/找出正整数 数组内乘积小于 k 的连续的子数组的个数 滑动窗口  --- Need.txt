### 解题思路
1. 鉴于对于第一次接触连续内积或连续和问题，开始一头雾水：
    - 按照教科书，花10分钟，尝试各种方法，把数学推理都用上了
    - 数学规律发现并推理，确实有用，就发现了滑动窗口方法：即注释的代码，比较晦涩；还是看正向的滑动窗口

2. 非注释代码是看了题解后做的，也就是“滑动窗口”思想，假如存在负数，滑动窗口应该解决不了
3. 也叫“双指针方法”
    - 时间复杂度：O(n)，其中 n是nums数组的长度。循环的时间复杂度为 O(n)，而 left 最多移动 n 次，因此总的时间复杂度为 O(n)。
    - 空间复杂度：O(1)。



### 代码

```python3
class Solution:
    def numSubarrayProductLessThanK(self, nums: List[int], k: int) -> int:
        '''
        # same to slide widow, but this is not work...
        pre_j = 0
        j = 0
        i = 0
        cj = 1
        len_list = len(nums)
        if len_list < 1 or k < 0:
            return 0
        cnt = 0
        while i <= j and j < len_list -1:
            if cj < k:
                cj *= nums[j]
                j += 1
            else:
                loop = j - i
                if loop > 0:
                    start = j - pre_j
                    for i in range(loop):
                        cnt += start
                        start -= 1 
                cj /= nums[i]
                i += 1
        return cnt 
        '''
        nsize = len(nums)
        if nsize < 1 or k < 1:
            return 0
        l = 0
        r = 0
        cj = 1
        ans = 0
        while r < nsize:
            cj *= nums[r]
            r += 1
            while l<r and cj >= k:
                cj /= nums[l]
                l += 1
            ans += r -l 
        return ans  















```