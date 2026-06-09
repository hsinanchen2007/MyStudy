![image.png](https://pic.leetcode-cn.com/5808d98ba844a260fd2042f309fa4768a954758c7a50363e02eea2b7df573eae-image.png)

给出的节点编号是有层次顺序的，所以逆遍历一次，就可以先计算出子结点的值和剩余节点数了。

如果以后新增的用例节点是乱序的，那就得实打实的建树，用后根序遍历遍历一次树就好了。

```python []
class Solution:
    def deleteTreeNodes(self, nodes: int, parent: List[int], value: List[int]) -> int:
        tree = [{'count': 0, 'sum': 0} for _ in range(nodes + 1)]
        for i in range(node - 1, -1, -1):
            tree[i]['sum'] += value[i]
            if tree[i]['sum']:
                tree[parent[i]]['count'] += tree[i]['count'] + 1
                tree[parent[i]]['sum'] += tree[i]['sum']
        return tree[-1]['count']
```
```python []
class Solution:
    def deleteTreeNodes(self, nodes: int, parent: List[int], value: List[int]) -> int:
        tree = [{'count': 0, 'sum': 0} for _ in range(nodes + 1)]
        for i, (p, v) in [*enumerate(zip(parent, value))][:: -1]:
            tree[i]['sum'] += v
            if tree[i]['sum']:
                tree[p]['count'] += tree[i]['count'] + 1
                tree[p]['sum'] += tree[i]['sum']
        return tree[-1]['count']
```