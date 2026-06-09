### 解题思路
用字符串序列大小排序一下简化解法

### 代码

```python3
class Solution:
    def minimumLengthEncoding(self, words: List[str]) -> int:
        words = [words[i][::-1] for i in range(len(words))]
        words = sorted(words)
        words = words[::-1]
        if len(words)==0:
            return 0
        ans = [0 for i in range(len(words))]
        st = words[0]+'#'
        ans[0] = 0
        for i in range(1,len(words)):
            if words[i] in st:
                ans[i] = 1
            else:
                st += (words[i] + '#')
        #print(st)
        return len(st)


```