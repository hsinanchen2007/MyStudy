
### 代码

```python3
class Solution:
    def numUniqueEmails(self, emails: List[str]) -> int:
        res = set()
        for i in emails:
            tmp = i.split("@")[0].replace(".", "")
            for j in range(len(tmp)):
                if tmp[j] == "+":
                    tmp = tmp[:j]
                    break
            tmp += "@"+i.split("@")[1]
            res.add(tmp)
        return len(res)
```