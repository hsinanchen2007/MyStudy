### 解题思路
最大的几个元素相加＞剩余元素的和
所以我将nums列表进行排序，不断从末尾pop出加在result列表中，若某一时刻result的和＞sum的和，则返回result

### 代码

```python3
class Solution:
    def minSubsequence(self, nums: List[int]) -> List[int]:
        nums.sort()
        result = []
        while len(nums)>0:
            result.append(nums.pop())
            if sum(result) > sum(nums):
                return result
```

### 执行结果
执行用时: 60 ms, 在所有 Python3 提交中击败了100.00%的用户
内存消耗: 13.7 MB, 在所有 Python3 提交中击败了100.00%的用户