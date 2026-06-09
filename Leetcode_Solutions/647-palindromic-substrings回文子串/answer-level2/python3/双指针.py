### 解题思路

i要能取到n-1,j能取到n,才能取到数组最后一个索引为n-1的数
### 代码

```python3
class Solution:
    def countSubstrings(self, s: str) -> int:
        count=0
        for i in range(len(s)):
            for j in range(i+1,len(s)+1):
                if s[i:j]==s[i:j][::-1]:
                    count+=1
        return count

```