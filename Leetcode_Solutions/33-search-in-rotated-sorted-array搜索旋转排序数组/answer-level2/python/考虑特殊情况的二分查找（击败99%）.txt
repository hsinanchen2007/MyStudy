执行用时 :28 ms, 在所有 Python3 提交中击败了99.73%的用户
内存消耗 :13.2 MB, 在所有 Python3 提交中击败了61.82%的用户

方法思路：
1.根据首尾判断是否旋转
2.若未旋转，直接二分查找（注意：可以直接判断target是否在首尾之内，否则直接返回-1）
3.若旋转，先找旋转点（以找到最大值为例）
（1）情况一：target在[0,index_max]之内：此范围二分查找
（2）情况二：target在[index_max+1,len(nums)-1]之内：此范围二分查找
（3）情况三：若不在以上两种情况则直接返回-1
```
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        if len(nums)<1:return -1
        #二分查找
        def two_find(m,n):
            if m>n:return -1
            mid = (m+n)//2
            if nums[mid]==target:
                return mid
            elif nums[mid]>target:
                return two_find(m,mid-1)
            else:return two_find(mid+1,n)
        #找旋转点，返回最大值处
        def find_max(m,n):
            mid = (m+n)//2
            if nums[mid]>nums[mid+1]:return mid
            elif nums[mid]>=nums[0]:return find_max(mid+1,n)
            else: return find_max(m,mid-1)
        
        if nums[0]<=nums[-1]:#如果数组没有旋转!("="是为了在nums长度为1时也能算进此)
            if target>=nums[0] and target<=nums[-1]:return two_find(0,len(nums)-1)
            else:return -1
        else:
            index_max = find_max(0,len(nums)-1)
            if target>=nums[0] and target<=nums[index_max]:return two_find(0,index_max)
            elif target>=nums[index_max+1] and target<=nums[len(nums)-1]:return two_find(index_max+1,len(nums)-1)
            else:return -1
```
