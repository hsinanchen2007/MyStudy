### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def balancedStringSplit(self, s: str) -> int:
        count=0
        res=0
        for c in s:
            if c=='R':
                count+=1
            if c=='L':
                count-=1
            if count==0:
                res+=1
        return res

```