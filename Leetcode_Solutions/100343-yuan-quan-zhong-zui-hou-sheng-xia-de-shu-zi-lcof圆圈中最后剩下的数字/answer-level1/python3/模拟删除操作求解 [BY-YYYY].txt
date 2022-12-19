### 解题思路
>这个题目是经典的约瑟夫环问题，使用模拟删除操作求解。

### 代码

```python3
class Solution:
    def lastRemaining(self, n: int, m: int) -> int:
        nums = list(range(n))
        del_index = 0
        while len(nums) > 1:
            del_index = (del_index + (m - 1)) % len(nums)
            nums.pop(del_index)
        return nums[0]
```

### 运行时间
执行用时 :2088 ms, 在所有 Python3 提交中击败了33.51%的用户
内存消耗 :17 MB, 在所有 Python3 提交中击败了100.00%的用户