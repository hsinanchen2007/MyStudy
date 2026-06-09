`python3`
```
class Solution:
    def defangIPaddr(self, address: str) -> str:
        return "".join([_ if not _ == "." else "[.]" for _ in address])
```
