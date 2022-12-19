执行用时 :32 ms, 在所有 Python3 提交中击败了99.04%的用户
内存消耗 :13.8 MB, 在所有 Python3 提交中击败了100.00%的用户


1.函数：以二分查找为基础，分别找到左边界和右边界
2.当target在nums[0]~nums[-1]之间时：
（1）找到左边界left
（2）若left==-1，则直接返回[-1,-1]
（3）若nums[left+1]!=target，则直接返回[left,left]
（4）其他情况：从[left+1,len(nums)-1]找右边界！注意不是从0~len(nums)-1
3.当target不在nums[0]~nums[-1]之间时：直接返回[-1,-1]


```
class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        #找最左边的
        def find_left(m,n):
            if m>n:return -1
            mid=(m+n)//2
            if (nums[mid]==target and mid==0) or (nums[mid]==target and nums[mid-1]!=target):return mid
            elif nums[mid]>target or (nums[mid]==target and nums[mid-1]==target):return find_left(m,mid-1)
            else:return find_left(mid+1,n)
        #找到最右边的
        def find_right(m,n):
            if m>n:return -1
            mid=(m+n)//2
            if (nums[mid]==target and mid==len(nums)-1) or (nums[mid]==target and nums[mid+1]!=target):return mid
            elif nums[mid]<target or (nums[mid]==target and nums[mid+1]==target):return find_right(mid+1,n)
            else:return find_right(m,mid-1)
        if len(nums)==0:return [-1,-1]
        if target >=nums[0] and target <=nums[-1]:
            left = find_left(0,len(nums)-1)
            if left==-1:return [-1,-1]#一个都找不到说明右边界也不用找了
            elif left==len(nums)-1 or nums[left+1]!=target:return [left,left]#如果只有一个target也不用再找右边界了
            else:return [left,find_right(left+1,len(nums)-1)]#不用0~-1找了！直接从left~-1里找
        else:return [-1,-1]
```
