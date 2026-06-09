### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        zero = -1
        i=0
        two = len(nums)
        while(i<two):
            if(nums[i]==2 and (i<two)):
                two-=1
                nums[i],nums[two]=nums[two],nums[i]
            elif(nums[i]==0 and (zero<i)):
                zero+=1
                nums[i],nums[zero]=nums[zero],nums[i]
                i+=1
            else:
                i+=1
```