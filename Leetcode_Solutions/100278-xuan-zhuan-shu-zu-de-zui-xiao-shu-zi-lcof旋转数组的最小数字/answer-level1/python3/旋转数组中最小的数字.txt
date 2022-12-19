### 解题思路

旋转数组的特性：其实是数组中有两个递增数列，不断缩小定位区间

### 代码

```python3
class Solution:
    def minArray(self, numbers: List[int]) -> int:

        left=0
        right=len(numbers)-1
        mid=left

        while (numbers[left] >= numbers[right]):
            if right-left ==1:
                return numbers[right]

            mid=(left+right)//2

            if (numbers[mid]==numbers[right])&(numbers[mid]==numbers[left]):
                return self.MinInorder(numbers,left,right)

            if numbers[mid] <= numbers[right]:
                right=mid
            elif numbers[mid] >=numbers[left]:
                left=mid

        return numbers[mid]


    

    def MinInorder(self,numbers,index1,index2):
        result=numbers[index1]

        for i in range(index1,index2):
            if result>numbers[i]:
                result=numbers[i]
        return result

   


```