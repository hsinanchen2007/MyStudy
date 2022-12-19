### 解题思路
集合交叉法 
排序后利用列表的切片方法，将nums分成两个不容的集合 
比如nums = [1,1,2,2,3,3,4]
利用python的切片赋值
s1 = [1,2,3,4]
s2 = [1,2,3]
s1 - s2 的最后一个数字 就是唯一的数字 

### 代码

```python3
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
    
        nums.sort() 
        n = list(set(nums[::2]) - set(nums[1::2]))[0]
        return n 
```