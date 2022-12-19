方法一：普普通通的动归，没什么好说的
```
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        if len(nums)==0:return 0
        if len(nums)==1:return 1
        dp=[1 for _ in range(len(nums))]
        for i in range(1,len(nums)):
            maxi=1
            for j in range(i):
                if nums[i]>nums[j] and dp[j]+1>maxi:maxi=dp[j]+1
            dp[i]=maxi
        return max(dp)
```
方法二：https://leetcode-cn.com/problems/longest-increasing-subsequence/solution/zui-chang-shang-sheng-zi-xu-lie-dong-tai-gui-hua-e/照人抄的，方法比较巧妙
很具小巧思。新建数组 cell，用于保存最长上升子序列。

对原序列进行遍历，将每位元素二分插入 cell 中。

如果 cell 中元素都比它小，将它插到最后
否则，用它覆盖掉比它大的元素中最小的那个。
总之，思想就是让 cell 中存储比较小的元素。这样，cell 未必是真实的最长上升子序列，但长度是对的。
```
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        size = len(nums)
        if size<2:
            return size
        
        cell = [nums[0]]
        for num in nums[1:]:
            if num>cell[-1]:
                cell.append(num)
                continue
            
            l,r = 0,len(cell)-1
            while l<r:
                mid = l + (r - l) // 2
                if cell[mid]<num:
                    l = mid + 1
                else:
                    r = mid
            cell[l] = num
        return len(cell)
```
