主要思路：
层序遍历每一节点时，当前节点应当作为父节点的儿子访问过，而子节点从未被访问
因此，环的情况如 3 [0, -1, -1] [-1, 1, -1] 也能检测到
```
class Solution(object):
    def validateBinaryTreeNodes(self, n, leftChild, rightChild):
        # 集合作为层序遍历队列的简化
        seen = set([0])
        # 迭代顺序即为层序遍历
        for i in range(n):
            lc, rc = leftChild[i], rightChild[i]
            if i not in seen: # 根结点应当出现过
                return False
            if lc in seen or rc in seen: # 子节点应当未出现过
                return False
            if lc!=-1:
                seen.add(lc)
            if rc!=-1:
                seen.add(rc)
        return True
```
