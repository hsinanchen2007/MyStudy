```
class Solution:
    def isPalindrome(self, x: int) -> bool:
        #如果输入负数，则肯定不是回文数
        if x<0:
            return False
        #将整数强制转换为字符型然后反转与原数相比较
        if str(x)==str(x)[::-1]:
            return True
        else:
            return False
```

