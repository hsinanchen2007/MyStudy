### 思路
先定义无重复，然后子串长度n初始为0。如果找到n+1的子串是无重复，就继续找更长的，如果n+1是有重复，坐标加一继续找。

### 代码

```python3
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        mLen = 0
        i = 0
        while (mLen+i) < len(s):
            if self.distinctString(s[i:(mLen+1+i)]):
                mLen += 1
            else:
                i += 1
        return mLen
    
    def distinctString(self, s_string):
        temp_set = set()
        for s in s_string:
            temp_set.add(s)
        isSubstring = True if len(temp_set)==len(s_string) else False
        return isSubstring
```