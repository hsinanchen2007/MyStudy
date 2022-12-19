### 解题思路
用注释了的写法实现会快一点，快20ms, 内存也占少一点
可以，但没必要~
### 代码

```python3
class Solution:
    def isPalindrome(self, x: int) -> bool:
        jq = str(x)
        qj = ""
        for i in jq:
            qj = i + qj
        return qj == jq
        # for l in range(0, len(jq)):
        #     if qj[l] != jq[l]:
        #         return False
        # return True
```