### 解题思路
1.Python中在一行定义多个变量要将变量都写在等号左边
2.sum()是Python内置函数，它的语法是：sum(iterable[, start])。
  start是加完列表后再加的数：如 sum((2, 3, 4), 1) = 10  
3.Python中的if..else和for循环都不要写括号，保持缩进即可
4.使用for循环时不需要手动写i++，它会自动计算

### 代码

```python3
class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        S,left_sum=sum(nums),0
        for i,x in enumerate(nums):
            if left_sum==(S-left_sum-x):
                return i
            left_sum+=x
        return -1
    #时间复杂度：O(N)。取决于nums的长度
    #空间复杂度：O(1)。使用了S和left_num
```