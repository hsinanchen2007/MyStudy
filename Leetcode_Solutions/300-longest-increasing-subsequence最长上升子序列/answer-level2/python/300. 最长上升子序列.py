### 解题思路
用另一个数组来保存最长序列，该数组一定满足上升序列，具体见程序

### 代码

```python
class Solution(object):
    def lengthOfLIS(self, nums):
        if not nums:return 0
        temp = []
        temp.append(nums[0])
        j = 0
        for i in range(1,len(nums)):
            if nums[i] > temp[j]:  #如果nums[i]大于temp数组最后一个元素，则将nums[i]加到最后
                temp.append(nums[i])
                j += 1
            else:
                for n in range(j+1): #如果nums[i]小于temp[-1]，则用nums[i]来替换temp中第一个大于或等于它的数，此时得到的temp不一定是此时真实的上升序列，但是能够保证上升序列的长度不变
                    if nums[i] <= temp[n]:
                        temp[n] = nums[i]
                        break
        return len(temp)
```