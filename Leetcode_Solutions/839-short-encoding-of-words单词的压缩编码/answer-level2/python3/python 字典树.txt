### 解题思路

构造字典树，对于每个单词从从后往前处理。
最后答案是每个叶子节点的层数的和（编码字符串中的单词长度） + 叶子节点数量（#数量）

### 代码

```python
class Solution:
    def minimumLengthEncoding(self, words: List[str]) -> int:
        class Node:
            def __init__(self, l):
                self.l = l # 层数
                self.children = {}
        
        root = Node(0)
        def build(t, w): # 递归构造字典树
            if not w:
                return
            if w[-1] not in t.children:
                t.children[w[-1]] = Node(t.l + 1)
            build(t.children[w[-1]], w[:-1])
        for w in words:
            build(root, w)
        ans = [0] # 相当于全局变量，以便在递归中累加

        def vis(t):  # 计算答案
            if len(t.children) == 0: # 是叶子节点
                if t.l > 0:
                    ans[0] += t.l + 1 # 累加
            for c in t.children.values():
                vis(c)
        vis(root)
        return ans[0]
```


相关题目：

字典树的非递归构造方法： [Kick Start 2020 Round A 第四题 python 解法](https://codeplot.top/2020/03/22/Round-A-2020-Kick-Start-2020-python-%E7%89%88%E4%BB%A3%E7%A0%81/#Bundling)
这个题因为层数很多，直接用递归方法导致栈溢出



[我的博客](https://codeplot.top/)

[博客刷题分类](https://codeplot.top/categories/%E5%88%B7%E9%A2%98/)