### 解题思路



很多细节：
1. python 的 string.sort() 和 sorted(A, key, reversed)
2. words.sort(key=lambda x: -len(x)) 
3. [字符串查找第一个匹配子串的 find 函数 和 index 函数](https://www.cnblogs.com/yangwu-183/p/10042755.html)： find 函数没找到会返回 -1， index 函数没找到会抛出异常
4. set.discard() 不存在不会报错 和 set.remove() 不存在会抛出异常， 用 discard 可以少一次 in 判断。

#### 官方题解两种解法写法非常奇妙
```python3
class Solution: # 解法1
    def minimumLengthEncoding(self, words: List[str]) -> int:
        good = set(words)
        for word in words:
            for k in range(1, len(word)):
                good.discard(word[k:])  # set 用 discard, 不用 remove

        return sum(len(word) + 1 for word in good)

class Solution: # 解法2， 复杂写法
    def minimumLengthEncoding(self, words: List[str]) -> int:
        words = list(set(words)) #remove duplicates
        #Trie is a nested dictionary with nodes created
        # when fetched entries are missing
        Trie = lambda: collections.defaultdict(Trie)
        trie = Trie()

        #reduce(..., S, trie) is trie[S[0]][S[1]][S[2]][...][S[S.length - 1]]
        nodes = [reduce(dict.__getitem__, word[::-1], trie) # 这里没太看懂
                 for word in words]

        #Add word to the answer if it's node has no neighbors
        return sum(len(word) + 1
                   for i, word in enumerate(words)
                   if len(nodes[i]) == 0)
```


[208. 实现 Trie (前缀树)](https://leetcode-cn.com/problems/implement-trie-prefix-tree/)
#### 更高级的解法： 官方题解 和 [字典树/Trie树/前缀树](https://leetcode-cn.com/problems/short-encoding-of-words/solution/99-java-trie-tu-xie-gong-lue-bao-jiao-bao-hui-by-s/)



### 代码

```python3
class Solution:
    def minimumLengthEncoding(self, words: List[str]) -> int:
        words.sort(key = lambda x:-len(x)) #不排序 ["me", "time"] 过不去
        S = "".join(words[0])
        S += "#"
        indexs = [0]
        for i in range(1, len(words)):   # ["time", "mea", "me","me", "bell"] 过不去
            # if S[len(S)-1-len(words[i]):len(S)-1] == words[i]:  # 可以从末尾(不考虑 '#')匹配
            #     indexs.append(len(S)-1-len(words[i]))
            # 使用 python3 语法
            k = S.find(words[i]+'#') # 但这里速度太慢了， 
            if k != -1:
                indexs.append(k)
            else:
                indexs.append(len(S))
                S += words[i]
                S += "#"
        return len(S)
        
```