### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def longestPalindrome(self, s: str) -> int:
        dic = {}
        ans = 0
        for i in s:
            if i not in dic:
                dic[i] = 1
            else:
                dic[i] +=1

        for i in dic.values():
            ans += (i//2)*2
            if ans%2==0 and i%2==1:
                ans +=1
        return ans
```


the very nice method for this problme