### format使用


### 代码

```python3
class Solution:
    def maskPII(self, S: str) -> str:
        if "@" in S:
            first,last = S.split("@")
            return "{}*****{}@{}".format(first[0],first[-1],last).lower()
        digits = list(filter(str.isdigit,S)) #Unicode.isdigit 在3中不存在，与2不同，filter之后是生成器list一下
        local = "***-***-{}".format(''.join(digits[-4:]))
        if len(digits) ==10:
            return local
        return "+{}-".format("*"*(len(digits)-10))+local
```