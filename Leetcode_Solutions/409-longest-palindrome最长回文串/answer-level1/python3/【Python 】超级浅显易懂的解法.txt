### 解题思路
组回文字符串的过程，其实我们可以看作是从一个中心往旁边对称放字符的过程。

首先我们先把给的字符串统计词频
（1）对于所有的出现偶数次的字符，那么其实在组回文字符串的时候就是可以看作直接放置在中心两侧，因此有多少就直接加上去多少就好了。
（2）对于所有的出现奇数次的字符，那么实际上我们就可以看作是1 + 偶数次，偶数次统统可以加上去，剩下的都是单个的不同的字符，选一个作为中心就好了。

要注意的是，如果给的字符串全是偶数次，那么肯定中心就不会一个单一的字符，所以要加一个判断，如果出现了有字符是奇数次那么就+1，否则对于全是偶数次的字符，就不需要加1了。 
### 代码

```python3
class Solution:
    def longestPalindrome(self, s: str) -> int:
        #统计字符词频
        s_cnt = collections.Counter(s)
        center = 0
        res = 0
        for char in s_cnt:
            #判断各个字符的词频奇偶
            if s_cnt[char] % 2:
                center = 1 #若出现奇数频次，center置为1
                res += s_cnt[char] - 1
            else:
                res += s_cnt[char]
        return res + center

```