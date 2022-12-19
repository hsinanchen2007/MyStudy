![image.png](https://pic.leetcode-cn.com/4e26d201bfdd8a94569c897cdb937e49461ac683074f3e0887792da56d80e283-image.png)

### 代码

```python3
class Solution:
    def translateNum(self, num: int) -> int:
        num = str(num)
        return self.fun(num)

    def fun(self,s):
        if not s or len(s) == 1:
            return 1
        # 只能选一位数或两位数，并且两位数不能大于25也不能0开头。
        if int(s[:2]) <= 25 and s[:2][0] != '0':
            return self.fun(s[1:]) + self.fun(s[2:])
        else:
            return self.fun(s[1:])


```