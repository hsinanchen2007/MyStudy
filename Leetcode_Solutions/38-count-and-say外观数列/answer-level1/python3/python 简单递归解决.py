思路：先获取上一个字符串，在将它读出来
```
class Solution:
    def countAndSay(self, n: int) -> str:
        if n == 1:
            return '1'
        val = self.countAndSay(n - 1)
        result = []
        count = 0
        for i in range(len(val)):
            count += 1
            if i + 1 < len(val) and val[i + 1] == val[i]:
                continue
            else:
                result.append(str(count) + str(val[i]))
                count = 0
        return ''.join(result)

```

