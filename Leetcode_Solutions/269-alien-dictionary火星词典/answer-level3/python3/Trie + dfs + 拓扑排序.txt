### 解题思路
三个medium难度题的集合

（1）先用trie构建树，并检查输入的合法性
（2）dfs trie中的顺序构造拓扑关系
（3）从入度为0开始，遍历所有的结果

### 代码

```python3
class Solution:
    def alienOrder(self, words: List[str]) -> str:
        trie = {"order": []}
        for w in words:
            t = trie
            for c in w:
                if c in t:
                    if t["order"][-1] != c:
                        return ""
                else:
                    t["order"].append(c)
                    t[c] = {"order": []}
                t = t[c]
            if len(t) > 1:
                return ""
            
        def dfs(node):
            if not node:
                return

            for k in node:
                value = node[k]
                if k == "order" and value:
                    level.add(value[0])
                    for i in range(1, len(value)):
                        in_degree[value[i]] = in_degree.get(value[i], set()) | {value[i - 1]}
                        out_degree[value[i - 1]] = out_degree.get(value[i - 1], set()) | {value[i]}
                else:
                    dfs(value)

        in_degree = {}
        out_degree = {}
        level = set()
        dfs(trie)

        #print(in_degree)
        #print(out_degree)
        level = {c for c in level if c not in in_degree}
        result = list(level)
        while level:
            new_level = set()
            for c in level:
                for c1 in out_degree.get(c, set()):
                    if c1 in in_degree and c in in_degree[c1]:
                        in_degree[c1].remove(c)
                        if len(in_degree[c1]) == 0:
                            in_degree.pop(c1)
                            result.append(c1)
                            new_level.add(c1)
            level = new_level
        return "".join(result)
```