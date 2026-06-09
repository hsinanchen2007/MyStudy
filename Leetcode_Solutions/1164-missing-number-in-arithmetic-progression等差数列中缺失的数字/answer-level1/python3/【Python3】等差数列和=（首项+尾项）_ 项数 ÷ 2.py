等差数列和=（首项+尾项）* 项数 ÷ 2
项数为当前arr中元素个数+1
“数列和”与“当前数组的和” 的差值就是要求的元素
```
class Solution:
    def missingNumber(self, arr: List[int]) -> int:
        return (arr[0] + arr[-1]) * (len(arr) + 1) // 2 - sum(arr)
```
