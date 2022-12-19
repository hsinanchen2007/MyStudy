### 解题思路
开头申明，用一行过每日一题是一种兴趣爱好，不是良好的代码习惯，对应试也没有帮助，不喜勿喷。

这题用Trie岂不是杀鸡用牛刀，排序去重就可以了！首先题目意思就是把所有共同后缀的字符串取出来，计算他们的总长度+总数（#号）即可。那么就要找到共同后缀的字符串。后缀往往不是很好处理，因此我们可以把所有字符串倒过来，这样就后缀变成前缀了。

然后排个序，所有共同前缀的字符串就自动跑到一起了，再判断、统计一下就ok了！

代码中w[::-1]表示字符串倒置，r[i+1].startswith(r[i])表示共同前缀的字符串取长度最大的那个，sum([len(r[i])+1 for ...])用于最后的统计。

### 代码

```python3
class Solution:
    def minimumLengthEncoding(self, words: List[str]) -> int:
        return (lambda r:sum([len(r[i])+1 for i in range(len(r)) if i==len(r)-1 or not r[i+1].startswith(r[i])]))(sorted([w[::-1] for w in words]))
```