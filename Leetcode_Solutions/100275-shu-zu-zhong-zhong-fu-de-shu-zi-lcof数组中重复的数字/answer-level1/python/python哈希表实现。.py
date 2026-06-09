### 解题思路
遍历数组，如果数组元素不在哈希表中，则哈希表增加该元素，如果在哈希表中，则返回该元素。

### 代码

```python3
class Solution:
    def findRepeatNumber(self, nums: [int]) -> int:
        dic={}
        for n in nums:
            if n in dic:
                return n
            else:
                dic[n]=1

```