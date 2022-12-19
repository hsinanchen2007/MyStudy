### 解题思路

当一个单词是另一个单词的后缀时，可以不需要创建新的索引，直接从索引位置读取即可。
判断是否是后缀，可以将单词倒序，转化为判断单词前缀的问题，通过构建字典树实现。
构建的字典树的分支有三种情况：
以单词 ["time", "me", "bell"，"atime", "btime"] 为例，构建了如下字典树。
① 只有一条分支，可以创建一个索引，需要计算索引长度；
② 单词结束标注在一个分支中，此时其中一个单词完全是另一个单词的后缀，创建新索引；
③ 两个单词结束标志在一个节点分裂为两条分支，此时两个单词无法共用一个索引，需创建新索引。
最后对创建好的字典树计算叶子节点的深度，累加起来即可，可以用DFS实现。

![clipboard.png](https://pic.leetcode-cn.com/20c189b964ef8c11f411a0c45dfdb9a43af679153a4fd1c4b1a798b57392e34d-clipboard.png)


### 代码

```python3
class Solution:
    def minimumLengthEncoding(self, words) -> int:
        revtrie = {}
        self.wordofstart = '#'
        for word in words:
            n = len(word)
            node = revtrie
            for i in range(n-1, -1, -1):
                node = node.setdefault(word[i], {})
            node[self.wordofstart] = self.wordofstart
        return self.countLeafDepth(revtrie, 0)
        
    def countLeafDepth(self, node, depth):
        if not node: return depth
        keys = set(node.keys())
        if len(keys) == 1 and self.wordofstart in keys:
            return depth + 1
        if self.wordofstart in keys: keys.remove(self.wordofstart)
        return sum([self.countLeafDepth(node[k], depth + 1) for k in keys])
```