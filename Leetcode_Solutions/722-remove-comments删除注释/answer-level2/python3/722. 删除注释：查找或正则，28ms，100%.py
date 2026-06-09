
![image.png](https://pic.leetcode-cn.com/2ea9c14eeb68b563b4d1c64c288daf640f6af82d75daddeab2b50e29d561a71a-image.png)

两种方法最快都是28ms，100%。

查找法，主要靠`find`函数：

```python []
class Solution:
    def removeComments(self, source: List[str]) -> List[str]:
        s = '\n'.join(source) + '\n' #为最后一行的'//'提供闭区间
        i, n = 1, len(s)
        ans = ''
        while i < n:
            if s[i - 1] + s[i] == '//':
                i = s.find('\n', i) + 1
            elif s[i - 1] + s[i] == '/*':
                i = s.find('*/', i + 1) + 3
            else:
                ans += s[i - 1]
                i += 1
        return filter(len, ans.split('\n'))
```

复杂的正则，如果愿意的话还可以再压缩一行：

```python []
class Solution:
    def removeComments(self, source: List[str]) -> List[str]:
        s = re.sub('//.*|/\*(\s|.)*?\*/', '', '\n'.join(source)) 
        return filter(len, s.split('\n'))
```
