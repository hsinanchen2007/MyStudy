### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def singleNonDuplicate(self, nums: List[int]) -> int:
        n=len(nums)
        l=0
        r=n-1
        # 不能等于号 会死循环
        while l<r:
            mid=l+(r-l)//2
            #如果mid是奇数 说明数组的的数的偶数 
            if mid%2==1:
                mid-=1
            if nums[mid]==nums[mid+1]:
                l=mid+2
            else:
                # mid是偶数 说明前部分多一个数
                r=mid
        return nums[l]

```