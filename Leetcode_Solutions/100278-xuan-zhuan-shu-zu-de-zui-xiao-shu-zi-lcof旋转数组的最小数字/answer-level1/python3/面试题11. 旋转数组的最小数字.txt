### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    # def minArray(self, numbers: List[int]) -> int:
    #     if not numbers:
    #         return 0
    #     for i in range(1,len(numbers)):
    #         if numbers[i] < numbers[0]:
    #             return numbers[i]
    #     return numbers[0]

    def minArray(self,numbers):
        i,j = 0,len(numbers)-1

        while i < j:
            m = (i+j)//2
            if numbers[m] > numbers[j]:
                i = m+1
            elif numbers[m] < numbers[j]:
                j = m
            else:
                j -= 1
        return numbers[i]
```