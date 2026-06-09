如题
```Python3
class Solution:
    def findOcurrences(self, text: str, first: str, second: str) -> List[str]:
        return re.findall(fr"(?<=\b{first} {second} )\S*", text)
```
