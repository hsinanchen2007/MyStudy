### 解题思路
不将整数转为字符串来解决的方法：通过取余、取整逐一取出数字，然后再通过相乘还原，最后判断数字是否相等而得到

### 代码

```python3
class Solution:
    def isPalindrome(self, x: int) -> bool:
        a = 0
        x_bk = x
        if x>0:
            while x>=1:
                if x>=10:
                    n = x%10
                else:
                    n = x
                a = a*10 + n  # 通过取出的数，还原数字
                x = int(x/10)
            if a==x_bk:  # 判断是否相等
                return True
            else:
                return False
        elif x==0:
            return True
        else:
            return False
```