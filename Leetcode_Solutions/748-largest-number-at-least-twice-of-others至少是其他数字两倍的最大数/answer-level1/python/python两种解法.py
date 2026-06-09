### 解题思路
1.如果列表长度为1，返回0
2.del掉最大元素，并判断最大元素与除掉最大元素后的列表的最大元素是否满足2倍的条件

### 代码

```python3
class Solution:
    def dominantIndex(self, nums: List[int]) -> int:
        if len(nums)==1:
            return 0
        else:
            max_num=max(nums)
            a=nums.index(max_num)
            del nums[a]
            if max_num>=max(nums)*2:
                return a
            else:
                return -1
```
第二种差不多，更简单一点
### 解题思路
判断最大与第二大是否满足条件
执行用时 :32 ms, 在所有 Python3 提交中击败了94.96%的用户
内存消耗 :13.1 MB, 在所有 Python3 提交中击败了53.31%的用户
### 代码

```python3
class Solution:
    def dominantIndex(self, nums: List[int]) -> int:
        if len(nums)==1:
            return 0
        else:
            max_num=max(nums)
            a=nums.index(max_num)
            nums.sort()
            if max_num>=nums[-2]*2:
                return a
            else:
                return -1
```