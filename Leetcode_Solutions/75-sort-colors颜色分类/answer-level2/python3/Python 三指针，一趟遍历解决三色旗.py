```
class Solution:
    def sortColors(self, nums: List[int]) -> None:
        '''三色旗问题，最初可将其看为四类：red，white，blue和unclassified
           |——0——|--1---|--unclassified--|--2---|
                 |      |                |
                red   white             blue
           当white与blue未重合时：
               如果nums[w]为0，则交换放到red区间，red和white都加1。
               如果nums[w]为1，则white指针加1。
               如果nums[w]为2，则交换放到 blue 区间，blue减1。
        '''
        r, w, b = 0, 0, len(nums) - 1
        
        while w <= b:
            if nums[w] == 0:
                nums[w], nums[r] = nums[r], nums[w]
                r += 1
                w += 1
            elif nums[w] == 1:
                w += 1
            else:
                nums[w], nums[b] = nums[b], nums[w]
                b -= 1
```
