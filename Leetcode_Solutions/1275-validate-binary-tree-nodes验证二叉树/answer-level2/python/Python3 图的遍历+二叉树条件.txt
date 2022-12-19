### 解题思路
分析出组成二叉树的条件即可
1.每个节点的入度只能为1（除头节点）
2.有且只能有一个入度为0的节点（头节点）
3.图的遍历必须能遍历到所有节点

### 代码

```python3
class Solution:
    def validateBinaryTreeNodes(self, n: int, leftChild: List[int], rightChild: List[int]) -> bool:
        import collections
        nextMap = collections.defaultdict(list)
        inMap = {}
        # 构建图
        for i in range(n):
            nextMap[i].append(leftChild[i])
            nextMap[i].append(rightChild[i])

        # 入度统计，不符合条件直接返回
        for i in range(n):
            if leftChild[i] != -1:
               
                inMap[leftChild[i]] = inMap.get(leftChild[i],0)+1
                if inMap.get(leftChild[i]) >= 2:
                    return False
        
            if rightChild[i] != -1:
                
                inMap[rightChild[i]] = inMap.get(rightChild[i],0)+1
                if inMap.get(rightChild[i]) >= 2:
                    return False
        # 找头节点，只能有一个
        head = [i for i in range(n) if i not in inMap]
        if len(head) !=1:
            return False
        # 图的BFS
        queue = []
        queue.append(head[0])
        res = []
        while queue != []:
            pp = queue.pop(0)
            res.append(i)

            if nextMap.get(pp) != None:
                for i in nextMap.get(pp):
                    if i != -1:
                        queue.append(i)
        return True if len(res) == n else False

        
```