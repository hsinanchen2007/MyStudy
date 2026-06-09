1.把前缀都压到一个map中。
例如lead,那么就将l,le,lea都压到map，map指向该前缀对应的具体单词
2.利用dfs查找对象，每次取i列的前缀，然后查找i列前缀对应的单词放到下一行。
3.遍历每个单词，进行dfs查找。

```
class Solution:
    def wordSquares(self, words: List[str]) -> List[List[str]]:
        #找到前缀树中所有前缀满足要求的词
        res = []
        d =collections.defaultdict(list)
        for word in words:
            for i in range(1,len(word)):
                d[word[:i]].append(word)
        
        def helper(word,i):
            if len(word[0])==i:
                res.append(word)
                return
            temp = ''.join([x[i] for x in word])            
            for char in d[temp]:
                helper(word+[char],i+1)
        
        for word in words:
            helper([word],1)
        return res
```
