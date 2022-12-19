### 解题思路
此处撰写解题思路
因为是有序数组，就想到二分查找，时间复杂度为nlogn 

### 代码

```python3
class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        lenth = len(numbers)
        for i in range(lenth):
            sub = target - numbers[i]
            j = i + 1
            k = lenth-1
            while j <= k:
                m = (j + k) // 2
                if numbers[m] == sub:
                    return i+1, m+1
                if numbers[m] < sub:
                    j = m + 1
                if numbers[m] > sub:
                    k = m - 1

        


```