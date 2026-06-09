python 3.2之后
collections.Counter 提供了加减方法。
Counter(t) - Counter(s)后返回值就是多出来的字母，list()后返回即可。
```
class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        return list(collections.Counter(t) - collections.Counter(s))[0]
```
