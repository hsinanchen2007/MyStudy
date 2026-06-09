![45b1ace9c91b0123a93149ec9c30df5.png](https://pic.leetcode-cn.com/b20321e1ed3ed033cc7637332c65e39e1aca595af380f07f48c02b5be5831f4c-45b1ace9c91b0123a93149ec9c30df5.png)
一 算法思路
层次遍历二叉树
将二叉树的结点依照层次序列（广度优先搜索序列）依次放入队列。当一个结点的左子结点为空时，若其右子结点不为空或其后的结点存在子结点，则不为完全二叉树；当一个结点的右子结点为空时，若其后的结点存在子结点，则不为完全二叉树。反之，则为完全二叉树。
二 算法实现
```
class Solution:
    def isCompleteTree(self, root: TreeNode) -> bool:
        de = collections.deque()
        flag = 0
        de.append(root)
        while de:
            p = de.popleft()
            if flag == 0:
                if p.left:
                    de.append(p.left)
                else:
                    if p.right:
                        return False
                    flag += 1
                if p.right:
                    de.append(p.right)
                else:
                    flag += 1
            else:
                if p.left or p.right:
                    return False
        return True
```
