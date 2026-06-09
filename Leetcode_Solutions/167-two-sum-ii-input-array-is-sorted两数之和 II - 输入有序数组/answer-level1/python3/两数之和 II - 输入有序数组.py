### 解题思路
借鉴大佬的双指针解法
由于是数组，一个指针i从前向后遍历，一个指针j从后向前遍历，如果 numbers[i]+numbers[j]大于目标值则j-1，如果 numbers[i]+numbers[j]小于目标值则i+1

### 代码

```python3
class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        # for i in range(len(numbers)-1):
        #     for j in range(i+1,len(numbers)):
        #         if numbers[i]+numbers[j] == target:
        #             return [i+1,j+1]
        if len(numbers) <= 1:
            return numbers
        i = 0
        j = len(numbers)-1
        while i<j:
            if numbers[i]+numbers[j]>target:
                j-=1
            elif numbers[i]+numbers[j]<target:
                i+=1
            else:
                return [i+1,j+1]
            
            
```