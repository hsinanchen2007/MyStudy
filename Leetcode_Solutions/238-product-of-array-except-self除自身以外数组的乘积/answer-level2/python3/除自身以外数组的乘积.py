### 解题思路
![image.png](https://pic.leetcode-cn.com/2ace851d94724593cb4d626fedb4bf11ed54e7cb1863442d06908bb1a5d560c5-image.png)

考虑数组`[a,b,c,d,e]`，则返回结果为`[1*bcde, a*cde, ab*de, abc*e, abcd*1]`可以拆分为两个列表对位位置元素相乘，即`[1,a,ab,abc,abcd]`和`[bcde, cde, de, e, 1]`；显然，这两个列表分别为数组`[a,b,c,d,e]`分别从左向右遍历和从右向左遍历时遍历元素的乘积；

因此用两次遍历即可完成；

时间复杂度：`O(n)`
空间复杂度：`O(1)`

### 代码

```python3
class Solution:
    """
    考虑数组[a,b,c,d,e]，从左到右遍历，tmp为当前遍历到的元素的乘积；
    将每次tmp更新的值放入列表L1中，即L1=[1, a, ab, abc, abcd]；
    再从右到左遍历[a,b,c,d,e]，tmp为当前遍历到的元素的乘积;
    将每次tmp更新的值也从右向左放入列表L2中，即L2=[bcde, cde, de, e, 1]
    
    返回结果res为L1与L2中相应位置的元素的乘积
    """
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        if len(nums) == 0:
            return []
        elif len(nums) == 1:
            return [1]
        elif len(nums) == 2:
            return [nums[1], nums[0]]

        res = [1]*len(nums)

        tmp = 1
        for i in range(len(nums)-1):
            tmp *= nums[i]
            res[i+1] *= tmp
        
        tmp = 1
        for i in range(len(nums)-1, 0, -1):
            tmp *= nums[i]
            res[i-1] *= tmp
        
        return res

```