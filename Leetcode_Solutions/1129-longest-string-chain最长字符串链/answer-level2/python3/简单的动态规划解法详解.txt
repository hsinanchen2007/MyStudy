**思路**

动态规划
 
1. “word1在任意位置添加一个字母变成word2”等价于“word2在任意一个位置减去一个字母变成word1”（假设叫做**逆前身**），则word中最长的词链就是[word_1,word_2,...,word_k]组成的序列，其中word_3是word_2的逆前身，word_2是word_1的逆前身，以此类推；
2. 假设有一个笔记本`note`，记录`words`中所有单词的词链长度`chain`，则对于`word`，他的最长词链长度为`chain = max(1,1+note[subWord])`，其中`subWord`表示的是`word`的每一个逆前身，且这个逆前身在`words`中（也就是说`note`中有`subWord`的记录）；
3. 对于`words`按照`word`的长度进行排序，排序后逐个对`word`按照步骤2的公式进行判断。如果`word`在`note`中没有记录，则说明`word`没有逆前身，他的`chain`为1.

**举例**

`words=["a","b","ba","bca","bda","bdca"]`
1. 初始化`note={}`
2. 对于`a`，`note`中无记录，则`chain`为1，`note={"a":1}`
3. 对于`b`，同上，`note={"a":1,"b":1}`
4. 对于`ba`，`chain=max(1,1+note[b],1+note[a])=2,note={"a":1,"b":1,"ba"=2}`
5. 对于`bca`，`chain=max(1,1+note[ba])=3,note={"a":1,"b":1,"ba"=2,"bca":3}`
6. 对于`bda`，同上，`note={"a":1,"b":1,"ba"=2,"bca":3,"bda":3}`
7. 对于`bdca`，`chain=max(1,1+note[bca],1+note[bda])=4`

遍历所有word之后，可知最大词链长度为4


**Python3代码**
```
class Solution:
    def longestStrChain(self, words):
        words.sort(key=len)
        note={}
        maxChain=1
        for word in words:
            if word not in note:
                note[word]=1
            for i in range(0,len(word)):
                newWord=word[:i]+word[i+1:]
                if (newWord) in note:
                    note[word]=max(note[word],note[newWord]+1)
            maxChain=max(maxChain,note[word])
        return maxChain
```
