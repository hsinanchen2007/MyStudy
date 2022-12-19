### 解题思路
直接使用join和split

### 代码

```python3
class Solution:
    def replaceSpace(self, s: str) -> str:
        # res=""
        # for ss in s:
        #     if ss==' ':
        #         res+='%20'
        #     else:
        #         res+=ss
        # return res
        return '%20'.join(s.split(' '))
```