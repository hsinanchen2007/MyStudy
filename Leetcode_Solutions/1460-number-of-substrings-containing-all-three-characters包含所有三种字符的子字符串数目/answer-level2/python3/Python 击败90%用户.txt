![image.png](https://pic.leetcode-cn.com/41519723b26debe1210ceadb155e21f0887f70c28080ebd1f6672a03c722655a-image.png)


```
'''
一个合法的字符串最后一次出现a b c的最短的一段是不可能变化的，在这一段
前面添加任何前缀都是合法的字符串，所以只需要枚举所有可能的 a b c最后一次
出现的位置可能的组合，设每个组合中最小的数值为x， 那前面可以添加x个前缀，
加上前缀为0的情况，总共会有x+1个合法子串产生，累加这些子串计数即可
'''


class Solution:
    def numberOfSubstrings(self, s: str) -> int:
        m = {'a':-1, 'b':-1, 'c':-1}
        ans = 0
        for i, ch in enumerate(s):
            m[ch] = i
            min_idx = min(m.values())
            if min_idx != -1:
                ans += min_idx + 1

        return ans
```
