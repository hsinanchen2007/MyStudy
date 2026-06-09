### 解题思路
哈希表高效思路(时间击败53.42%，内存击败100%)
以为内存很垃圾，但还是击败100%

------------- --------------
(py3解法)
建立一个set-注：py3哈希表库
遍历nums
有就返回当前数值
没有就在set里插入当前数值
------------ -----------------
用py3的人注意用set
不要用其他的(比如list,dict)
效率不高
list直接超时
### 代码

```python3
class Solution:
    def findRepeatNumber(self, nums: List[int]) -> int:
        findnums=set()
        for i in nums:
            if i in findnums:
                return i
            else:
                findnums.add(i)
```