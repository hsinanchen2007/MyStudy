![7430eca50813137eacafa5af77514c0.jpg](https://pic.leetcode-cn.com/c76c68723b360b178bcdd005ce8c157126af94f66ba66834609306c4b3346eb1-7430eca50813137eacafa5af77514c0.jpg)
本题用正则表达式匹配，应该是最快的。代码如下：
```python []
import re  # use re module to process regular expression matching problems


class Solution:
    def expressiveWords(self, S: str, words) -> int:
        pattern = '^'  # '^' match the start of target word
        a = [i for i in range(len(S)) if i == 0 or S[i] != S[i-1]] + [len(S)]  # record the start indexes of continuous same letter; e.g.'aaabbcc': [0, 3, 5]
        # print(a)
        for i in range(1, len(a)):
            cha, num = S[a[i]-1], a[i] - a[i-1]  # cha is the continuous same letters, num is length
            print(cha, num)
            if num < 3: 
                pattern += cha * num  # if num < 3, it means not stretchy, so the regular expression should be this 'cha' itself
            if num >= 3:
                pattern += '%s{1,%d}' % (cha, num)  # if num > 3, it means any length that not longer than num (but need to exist) could be OK, so the regular expression is '%s{1,%d}'
        pattern += '$' # '$' match the end of target word
        # print(pattern)
        res = 0 # use res as a count
        for word in words:
            if re.match(pattern, word):
                res += 1 # use regular expression to match word in words one by one
        return res
```
