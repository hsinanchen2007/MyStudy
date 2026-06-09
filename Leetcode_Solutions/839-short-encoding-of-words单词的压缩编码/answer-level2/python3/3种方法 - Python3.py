## 解法一（暴力法）
思路：对列表中所有字符串进行两两对比，如果字符串A属于字符串B的尾巴，则删除字符串A，统计最后剩余的字符串的总长度，即为题目所求。

1. 对列表中字符串按字符串长度，由大到小排序
2. 依次对所有字符串进行两两比较，对于每个母串，需要增加一个#分隔符
3. 统计所有母串长度，并累计分隔符个数
* 时间复杂度：O(N^2^)
* 空间复杂度：O(N)

```python
# author: suoxd123@126.com
class Solution:
    def minimumLengthEncoding(self, words: List[str]) -> int:
        words = list(set(words)) #去重
        words.sort(key = lambda x:len(x), reverse=True)#按长度右大到小排序
        rstCnt, wordsCnt = 0, len(words)
        wordsLen = [len(x) for x in words]#获取长度，减少循环中多次获取
        for i in range(0,wordsCnt):
            if len(words[i]) == 0:#字符串已经被删除
                continue
            rstCnt += wordsLen[i] + 1# 1是井号分隔符
            for j in range(i+1,wordsCnt):
                if len(words[j]) == 0:
                    continue
                if words[i][wordsLen[i] - wordsLen[j]:] == words[j]:#j是i的尾巴
                    words[j] = ''
        return rstCnt
```

***
## 解法二（后缀清除）
思路：对列表中的每个字符串，删除其后缀中包含的所有其它字符串，统计最后剩余的字符串长度
1.  将列表转换为集合，可以去重
2. 利用集合的discard函数，删除所有匹配到后缀的字符串集合
3. 统计最后剩余字符串的长度，并增加井号分隔符个数
* 时间复杂度：O(N len(N))
* 空间复杂度：O(N)
```python
# author: suoxd123@126.com
class Solution:
    def minimumLengthEncoding(self, words: List[str]) -> int:
        wordSet = set(words) #清除重复字符串，并返回set集合
        for word in words:
            for i in range(1,len(word)):
                wordSet.discard(word[i:]) #删除当前字符串所有后缀相同的子串集合
        rstCnt = sum([len(x) + 1 for x in wordSet])
        return rstCnt
```
***
## 解法三（字典树）
思路：将所有字符串组成一个字典树，统计所有树枝对应字符串长度，由于是对字符串后缀匹配，所以将字符串反转后构建字典树。
1. 首先对原始数据去重，并对字符串反转
2. 构建字典树，并存储当前节点深度
3. 遍历字典树，累计叶子节点深度值
* 时间复杂度：O(N len(N))
* 空间复杂度：O(N)
```python
# author: suoxd123@126.com
class TrieNode:
    def __init__(self):
        self.children = {}
        self.dept = 0 # 叶子节点深度

    #构建字典树
    def addWord(self,word:str, idx: int):
        if idx >= len(word):
            return
        tmpNode =  self.children[word[idx]] if self.children.__contains__(word[idx]) else TrieNode()
        tmpNode.dept = idx + 1 
        tmpNode.addWord(word,idx+1) #递归构建
        self.children[word[idx]] = tmpNode 

    #统计树中节点个数
    def count(self):
        rst = 0 
        for k in self.children:
            rst += self.children[k].count() #递归累加        
        if not self.children :# 统计所有叶子节点的深度，1是井号分隔符
            return self.dept + 1
        return rst

class Solution:
    def minimumLengthEncoding(self, words: List[str]) -> int:
        words = [word[::-1] for word in set(words)]#去重，反转
        trie = TrieNode()
        for word in words:
            trie.addWord(word,0)
        return trie.count()
```


欢迎大佬们，随手关注VX公众号【[真相很简单](https://www.zhenxiangsimple.com/categories/tech/math/)】，拍砖指导，查看一题多解

![zhenxiangSimple](https://pic.leetcode-cn.com/f5cdcda21a37ab2959ff8c7fa75e174b326a0b126a27296ba28e906b7309dab1-zhenxiangSimple.jpg)