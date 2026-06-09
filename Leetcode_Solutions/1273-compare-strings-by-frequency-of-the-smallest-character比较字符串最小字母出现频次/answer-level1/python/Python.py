思路：

按照题意分别对 words 和 queries 计算出其最小字符出现的次数，依次对每个 query 返回 words 中比其大的数量即可

代码实现：

```python
class Solution(object):
    def numSmallerByFrequency(self, queries, words):
        """
        :type queries: List[str]
        :type words: List[str]
        :rtype: List[int]
        """
        ret, queries_count, words_count = [], [], []
        words_count = [word.count(min(word)) for word in words]
        for query in queries:
            c = query.count(min(query))
            # 在 words_count 里数一下有多少是比 c 大的
            ret.append(len([x for x in words_count if c < x]))
        return ret
```

更多题解欢迎关注 [Do Leetcode For Fun](https://zhuanlan.zhihu.com/c_1145647496591298560) 专栏~
