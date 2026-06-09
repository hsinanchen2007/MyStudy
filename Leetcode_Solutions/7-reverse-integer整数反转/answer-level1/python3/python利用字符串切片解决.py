### 解题思路
执行用时 :24 ms, 在所有 Python3 提交中击败了99.26%的用户

### 代码

```python3
class Solution:
    def reverse(self, x:int) -> int:
            s = str(x)
            new_str =''
            le = len(s)-1
            if len(s) == 1 :
                return int(s)
            while le>=0 :
                if s[le] == '0':
                    s = s[:le]
                    le -= 1
                else:
                    break
            if s[0] == '-':
                new_str += s[0]
                s = s[1:]
            new_le = len(s) - 1
            while new_le>=0 :
                new_str += s[new_le]
                new_le -= 1
                x = int(new_str)
            if x not in range(-2**31,2**31) :
                return 0
            else :
                return x
```