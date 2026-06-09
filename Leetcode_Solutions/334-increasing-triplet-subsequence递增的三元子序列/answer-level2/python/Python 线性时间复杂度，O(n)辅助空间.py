**思路**
先进行两次遍历，分别记录“该元素左边最小的值”和“该元素右边最大的值”
再进行一次遍历，如果nums[i]比“该元素左边最小的值”更大，比“该元素右边最大的值”更小，则说明存在这样一个三元递增子序列，返回TRUE
如果遍历完毕，即说明没有找到这样一个nums[i]，返回FALSE
遍历3次，时间复杂度O（n），用两个大小为n的辅助数组，空间复杂度O（n）
```
class Solution(object):
    def increasingTriplet(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        lenn=len(nums)
        if lenn<3:return False
        lmin=[nums[0]]*lenn
        rmax=[nums[lenn-1]]*lenn
        for i in range(1,lenn):
            lmin[i]=min(lmin[i-1],nums[i-1])    #注意，lmin[i]表示的是该元素左边最小的值，不包括第i个元素本身
        for i in range(lenn-2,-1,-1):
            rmax[i]=max(rmax[i+1],nums[i+1])
        for i in range(1,lenn-1):
            if nums[i]>lmin[i] and nums[i]<rmax[i]:
                return True
        return False
```
