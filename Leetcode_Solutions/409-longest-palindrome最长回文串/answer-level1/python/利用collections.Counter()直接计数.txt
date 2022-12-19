### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def longestPalindrome(self, s: str) -> int:
        init_len = len(s)
        counts = collections.Counter(s) #生成元素计数dict
        res = 0
        for _, count in counts.items():#在字典中累加计数
            res += (count-count%2)
        if res<init_len: res+=1 #最后长度小于init_len 肯定有奇数
        return res

#另解：利用hash table
```