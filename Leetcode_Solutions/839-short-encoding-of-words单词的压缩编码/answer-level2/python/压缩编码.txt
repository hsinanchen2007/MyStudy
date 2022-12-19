### 解题思路
 # 突破点：因为只能通过'#'来表示单词的结束，所以如果某个单词能通过包含它的单词来索引，那么它只能出现在那个单词的最后
    # 因此可以通过将每个词翻转并排序后循环处理



### 代码

```python
class Solution(object):
    def minimumLengthEncoding(self, words):
        """
        :type words: List[str]
        :rtype: int
        """
        words = sorted(w[::-1] for w in words)
        res = [len(words[0])]
        for i in range(1, len(words)):
            if words[i].startswith(words[i - 1]):  # 前一个被它包含
                res[-1] = len(words[i])  # 则用新的这个替换前一个作为之前几个被包含项的的索引字符串
            else:  # 前一个不能被其包含
                res.append(len(words[i]))  # 新增一个字符串用来索引
        return sum(res) + len(res)  # len(res)是'#'的个数
```