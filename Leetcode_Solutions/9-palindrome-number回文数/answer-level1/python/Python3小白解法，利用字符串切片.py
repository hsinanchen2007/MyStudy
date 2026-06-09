切片slice 操作可以让我们快速的提取子字符串。标准格式为：
[起始偏移量start：终止偏移量end：步长step]

```
class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x<0:
            return False
        elif 0<=x<9:
            return True
        else:
            str_x = str(x)
            if str_x[::-1]==str_x:#步长为负，从右到左反向提取
                return True
            else:
                return False
```

