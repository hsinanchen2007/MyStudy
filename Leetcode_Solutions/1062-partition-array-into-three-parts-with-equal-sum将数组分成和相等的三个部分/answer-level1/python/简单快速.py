### 解题思路
执行用时 :52 ms, 在所有 Python3 提交中击败了99.05% 的用户
内存消耗 :18.7 MB, 在所有 Python3 提交中击败了98.06%的用户

### 代码

```python3
class Solution:
    def canThreePartsEqualSum(self, A: List[int]) -> bool:
        amount = sum(A)
        if amount % 3 != 0:
            return False
        res = amount // 3
        temp, count = 0, 0
        for i in A:
            if count == 2:
                return True
            temp += i
            if temp == res:
                count += 1
                temp = 0
        return False

```