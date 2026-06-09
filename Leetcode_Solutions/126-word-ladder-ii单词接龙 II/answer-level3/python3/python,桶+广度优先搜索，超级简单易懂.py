### 解题思路
总体思路同单词接龙I，只需增加考虑多种可能路径即可。
1.将所有单词构建桶，便于查找邻接词。构建桶的方式是依次将一个词的各个字母挖空，用字典进行保存

2.广度优先搜索进行遍历，这里构建三个数据结构：
-   befound：用于标记首次遍历的词，同时记录首次遍历的深度，以区分
-   pres：用一个默认列表字典实现，用于记录到达该节点的前溯词列表，这里需注意对于每个可能搜索到该词的路径，只要深度不超过已有路径，都应加入前溯词列表
-   toSeen：用一个双端队列实现，用于存储待遍历词及当前深度。

3.如果搜索到了目标节点endWord，则依次往前递归输出解：每个解的头节点若包含多个前溯词，则解相应增加。利用python列表嵌套推导式实现。

### 执行结果
![image.png](https://pic.leetcode-cn.com/c8b2f6bc1e88003b18dc84103ead0bc1e882c832fec18b65182ddb1a0ca0c1a2-image.png)

### 代码

```python3
class Solution:
    def findLadders(self, beginWord: str, endWord: str, wordList: List[str]) -> List[List[str]]:
        wordList.append(beginWord)
        ### 构建具有邻接关系的桶
        buckets = collections.defaultdict(list)
        for word in wordList:
            for i in range(len(beginWord)):
                match = word[:i] + '_' + word[i+1:]
                buckets[match].append(word)
        ##### BFS遍历
        pres = collections.defaultdict(list)#前溯节点
        toSeen = collections.deque([(beginWord, 1)])#待遍历列表及当前深度
        befound = {beginWord:1}#已探测到的词列表
        while toSeen:
            cur, level = toSeen.popleft()
            for i in range(len(beginWord)):
                match = word[:i] + '_' + word[i+1:]
                for word in buckets[match]:
                    if word not in befound:
                        befound[word] = level+1
                        toSeen.append((word, level+1))
                    if befound[word] == level+1:#当前深度等于该词的首次遍历深度，则仍应加入前溯词列表
                        pres[word].append(cur)
            if endWord in befound and level+1 > befound[endWord]:#已搜索到目标词，且完成当前层遍历
                break
        #### 列表推导式输出结果
        if endWord in befound:
            res = [[endWord]]
            while res[0][0] != beginWord:
                res = [[word] + r for r in res for word in pres[r[0]]] 
            return res
        else:
            return []
```
