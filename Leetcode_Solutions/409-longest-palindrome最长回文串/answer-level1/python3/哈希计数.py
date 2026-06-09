### 解题思路
构建哈希表，得到每个字母的以及其出现次数
回文数是对称的，如果回文数的长度为奇数，将中间的字符拿出来其实也可构成对称
故而只需要求出题目所给的每个字符i最多可组成多少对value[i]，这就能构成回文，长度为sum(value)*2
再考虑，只要出现某字符键值为奇数，则该字符就可以作为回文数的中间字符,但需要注意，中间字符只能有一个
建立flag，除非题目所给字符键值全为偶，否则，必然出现无法配对的数，可作为回文中间数




### 代码

```python3
class Solution:
    def longestPalindrome(self, s: str) -> int:
        s_cnt=collections.Counter(s)
        k=0
        flag=0
        for i in s_cnt:
            value=s_cnt[i]//2
            r=s_cnt[i]%2
            k=k+value*2
            flag=flag+r
        if flag>0:
            flag=1
        return k+flag
        
```