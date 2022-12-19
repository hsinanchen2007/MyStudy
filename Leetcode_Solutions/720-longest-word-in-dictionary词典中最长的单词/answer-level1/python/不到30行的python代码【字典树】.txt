不到30行的一份代码
思路：
1. 先按长度排序，保证了先后顺序关系
2. 然后遍历排序后的单词
3. 若单词长度为1，则直接放入trie
4. 若单词s长度>1，且s[:-1]不在trie内，则这个单词直接不要了
5. 若单词s长度>1，且s[:-1]在trie内，判断这个单词的长度，决定是否加入result集合
6. 最后得到result集合按照字典序排序，输出第一位
7. NOTE这里判断s[:-1]是否在trie内的方法如下的intrie()函数
```
class Solution(object):
    def longestWord(self, words):
        """
        :type words: List[str]
        :rtype: str
        """
        def intrie(s):
            t = trie
            for si in s[:-1]:
                if si not in t:
                    return False
                t = t[si]
            t[s[-1]] = {}
            return True
        
        trie = {}
        words.sort(key = lambda x: len(x))
        maxlen = 0
        result = []
        for aw in words:
            if len(aw) == 1:
                trie[aw] = {}
            else:
                if not intrie(aw):
                    continue
            if len(aw) > maxlen:
                result = [aw]
                maxlen = len(aw)
            elif len(aw) == maxlen:
                result.append(aw)
                
        return sorted(result)[0] if result else result
```
