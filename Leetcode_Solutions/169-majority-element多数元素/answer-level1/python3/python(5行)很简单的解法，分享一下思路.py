### 解题思路
这题真的是我最近遇到的最简单的题目了。
思路就是遍历数组元素的同时，**用字典随时记录元素出现的次数**

当出现次数**大于** `⌊ n/2 ⌋`时迭代终止，返回元素

时间复杂度和空间复杂度均为$o(n)$

### 代码

```python
class Solution(object):
        hashmap = {}
        for i in nums:
            hashmap[i] = hashmap.get(i, 0) + 1
            if hashmap[i] > (len(nums) // 2):
                return i
```