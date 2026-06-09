# **思路：单词A出现在单词B的末尾，则A可以被B merge**
   **A = time
   B = me
   则 B == A[3:] B单词可以被A merge掉**
   **时间O(n)
   空间O(n)**
```
class Solution:
    def minimumLengthEncoding(self, words: List[str]) -> int:
        #  将每一个单词加入hashset中
        wordSet = set()
        for i in words:
            wordSet.add(i)
        #  遍历words中的每个单词，检查其word[1:],word[2:],...,word[-1:]后缀是否在wordSet中
        #  例如,word[3:]如果在wordSet中 ，则说明word[2:]可以被merge。 比如（time，me）
        for word in words:
            for part in range(1,len(word)):
                # 如果word[part:]在 wordSet 中,则word[part:]可以被merge到word中
                # 则将其(word[part:])从set中移除
                if word[part:] in wordSet:
                    wordSet.remove(word[part:])
        total = 0
        # 最后统计wordSet中所剩单词每个长度总和 再加上len(wordSet)即可（#的个数）
        for word in wordSet:
            total+=len(word)
        return total+len(wordSet)
```
