## 思路
第一个想到的和官方题解一样，用两个指针的移动。第一个指针从前往后，第二个指针从后往前，根据大小调整指针的移动。

完全没有想到二分法什么的，也不知道是好事还是坏事......
## 代码
```py
class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        i , j = 0 ,len(numbers) - 1
        while i < j:
            if numbers[i] + numbers[j] > target:
                j -= 1
            elif numbers[i] + numbers[j] < target:
                i += 1
            else:
                return [i+1,j+1]
```