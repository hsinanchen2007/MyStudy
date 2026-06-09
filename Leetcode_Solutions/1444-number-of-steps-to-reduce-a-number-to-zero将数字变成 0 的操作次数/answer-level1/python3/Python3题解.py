### 解题思路
模拟运算过程，最后由于num为1时判定为奇数会多加一个1，需要减去
执行用时 :36 ms, 在所有 Python3 提交中击败了100.00% 的用户
内存消耗 :13 MB, 在所有 Python3 提交中击败了100.00%的用户

### 代码

```python3
class Solution:
    def numberOfSteps (self, num: int) -> int:
        count = 0
        while num:
            if num % 2 == 0:
                count += 1
            else:
                count += 2
            num //= 2
        return count-1
```