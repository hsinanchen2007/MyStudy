### 解题思路
对于给定的字符串，要找出最大的无重复子串长度，首先考虑出现情况，第一子串为本身，子串在串内
第一种情况就是答案就是本身长度，第二种情况给字符一个游标记录匹配位置，然后用一个list记录子串，得到长度即可，不断更新最大长度值，代码如下

### 代码

```python3
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        count = 0;
        max_count = 0;
        i = 0; #i是下标
        j = 0;
        l = len(s)
        temp = [];
        set_l = len(set(s))
        while True:
            if i<l:
                if s[i] in temp:
                    temp = []
                    count = 0
                    j+=1
                    i = j
                else:
                    temp.append(s[i])
                    count = len(temp)
                    max_count = count if count>max_count else max_count
                    i+=1
            else:
                break
        return max_count if set_l!=l else l
   
```