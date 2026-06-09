### 解题思路

写给自己复习时，要注意的两个点：
1. 首先是if语句中，要在dict里找，而不是在nums里找
2. 关于查重：由于题目限制 ( i != j ) 看到其他解法中要考虑到判断是否找到的数为本身。
    在python dictionary中，每个key是唯一的。
    而我们只遍历list一次，list里本身的数字没有重复，所以每个数最多只会在dict中作为key存储一次。


### 代码

```python3
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        dict = {}
        for i in range(len(nums)): #遍历所有数字，num1
            if (target - nums[i]) in dict:  ## num2=target-num1, 如果num2在dict里，
                j = dict[target - nums[i]]  ## 则找到num2对应的value(也就是下标）
                return [i, j]
            else:
                dict[nums[i]] = i
```