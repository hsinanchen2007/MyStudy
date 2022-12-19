### 解题思路

abc 排列可以分成三部分：  a + bc排列；b + ac排列； c + ab排列
aab 排列可以分成两部分：  a + ab 排列； b + aa排列

bc 排列可以分成两部分： b + c排列； c + b排列
bb 排列可以分成一部分： b + b排列

b 排列输出 b


### 代码

```python3
class Solution:
    def permutation(self, s: str) -> List[str]:
        res = []
        if len(s) <= 1:        ##字符数为1或空时，只有一种排列，就是本身
            return [s]
        i = 0
        ##set 记录以某个字符开头的排列（重复字符不会再排列）
        ## 例如aab，当循环到第二个a时，a + ab排列和第一个a重复
        char_set = set()  
        while i < len(s):
            if s[i] in char_set:  ## 判断，若此字符与之前字符重复，则跳过
                i += 1
                continue
            char_set.add(s[i])
            first_char = s[i]
            last_s = s[:i] + s[i+1:]   ##除了当前字符以外的其他字符
            last_list = self.permutation(last_s)
            for st in last_list:        ## 以此字符开头 + 其他字符所有排列
                new_char = first_char + st
                res.append(new_char)
            i += 1
        return res
```