### 解题思路
此处撰写解题思路
非常简单，但自己还是出现了几次问题，审题不清楚
用单词来构成回文字符串，没说某个单词必须全部用，，所以前面几次就出错了，凡是奇数个都没加上去。
奇数个减一就可以用了。然后最后在补上一个1 即可，如果需要的话。
### 代码

```python3
class Solution:
    def longestPalindrome(self, s: str) -> int:
        dic = collections.Counter(s)
        ans = 0
        flag=False
        for k,v in dic.items():
            if v%2==0:
                ans+=v
            else:
                flag=True
                ans+=v-1

        return ans+1 if flag else ans

        
            
```