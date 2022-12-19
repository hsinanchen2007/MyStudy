```
class Solution:
    def maximumProduct(self, nums: List[int]) -> int:
        nums.sort()  #先排序,1:全为正数 2:全为负数 3:1负2正 4:其中1个为0  总共7种情况
        a, b, c = nums[:3]  #7种情况分析后只有3个结果
        d, e, f = nums[-3:]
        return max(a*b*f,a*e*f,d*e*f)
```
