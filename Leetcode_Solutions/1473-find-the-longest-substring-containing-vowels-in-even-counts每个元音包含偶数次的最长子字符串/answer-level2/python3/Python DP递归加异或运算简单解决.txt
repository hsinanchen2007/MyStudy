![image.png](https://pic.leetcode-cn.com/7fff4f4f0257fa9e3ac7f722e46a0207976d36b4858fa678565316db8176f164-image.png)


```
'''
[0, i]区间内元音字母的出现次数奇偶性可以用一个5bit数值表示为dp[i]
如果j < i 且 dp[i] == dp[j] 那[i+1, j]区间 就是一个合法区间，
动态规划递推，枚举所有可能的最长区间，只需要维护5bit数值第一次出现
的位置即可， 一遍线性扫描可以解决

'''

class Solution:
    def findTheLongestSubstring(self, s: str) -> int:
        first_pos = {0 : -1}
        ch2idx = {'a':0, 'e':1, 'i':2, 'o':3, 'u':4}

        val = 0
        max_len = 0
        for i, ch in enumerate(s):
            if ch in 'aeiou':
                val ^= (1 << (ch2idx[ch]))
            if val not in first_pos:
                first_pos[val] = i
            else:
                max_len = max(max_len, i - first_pos[val])
        return max_len
```
