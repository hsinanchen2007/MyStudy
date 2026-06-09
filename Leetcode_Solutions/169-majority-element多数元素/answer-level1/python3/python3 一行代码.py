### 解题思路
多数元素的数量占列表的一半以上。所以对列表进行排序，中间右移一位的值即为多数元素。
例如：
[1122222] >>> 2
[1111122] >>> 1

### 代码

```python3
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        return sorted(nums)[len(nums)//2]
```