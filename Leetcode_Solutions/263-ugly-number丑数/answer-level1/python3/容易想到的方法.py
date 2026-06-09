### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def isUgly(self, num: int) -> bool:
        if num<=0:
            return False
        while num>1:
            if num%2==0:
                num=num/2
            else:
                if num%3==0:
                    num=num/3
                else:
                    if num%5==0:
                        num=num/5
                    else:
                        return False
        return True
```