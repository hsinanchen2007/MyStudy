### 解题思路
执行用时 :24 ms, 在所有 Python3 提交中击败了97.81% 的用户
内存消耗 :13.4 MB, 在所有 Python3 提交中击败了5.09%的用户

### 代码

```python3
class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        if not s:
            return 0
        count = 0
        flag = 0
        for i in s[::-1]:
            if i is " " and flag == 0:
                continue
            if i is not " ":
                count += 1
                flag = 1
            else:
                break
        return count
```