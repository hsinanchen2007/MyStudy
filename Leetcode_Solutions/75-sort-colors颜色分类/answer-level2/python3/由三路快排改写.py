### 解题思路
利用三路快排，设置索引点，zero,i,two,nums[i]=1时不变，nums[i]<1时与nums[zero]交换位置，nums[i]>1时与nums[two]交换位置

### 代码

```python3
class Solution:
    def sortColors(self,nums:[int]):
        zero=-1
        two=len(nums)
        i=0
        while i <two:
            if nums[i]<1:
                zero+=1
                nums[zero],nums[i]=nums[i],nums[zero]
                i+=1
            elif nums[i]>1:
                two-=1
                nums[i],nums[two]=nums[two],nums[i]
            else :
                i+=1
        return nums

```