### 解题思路
构建一个后缀字典树并通过dfs统计每条路径的长度

### 代码

```python3
class Solution:
    def minimumLengthEncoding(self, words: List[str]) -> int:
        #构建trie树
        root={'length':0}
        def insert(word):
            cur=root
            for w in word[::-1]:
                if w not in cur:
                    cur[w]={'length':cur['length']+1}
                cur=cur[w]
        for word in words:
            insert(word)

        #用dfs遍历trie树
        res=0
        def dfs(cur):
            #若当前字典长度为1，即只有'length'这个键，说明已经是结尾了
            if len(cur)==1:
                nonlocal res
                #每次累加字符串和'#'的长度
                res+=cur['length']+1
                return
            for i in cur:
                if i !='length':
                    dfs(cur[i])
        dfs(root)
        return res
```