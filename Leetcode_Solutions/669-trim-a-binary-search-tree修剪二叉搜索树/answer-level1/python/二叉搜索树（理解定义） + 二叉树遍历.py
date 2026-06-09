### 解题思路
1. **二叉搜索树的定义要理解：**
    - 二叉查找树（Binary Search Tree），（又：二叉搜索树，二叉排序树）它或者是一棵空树，或者是具有下列性质的二叉树： 
    - 若它的左子树不空，则左子树上所有结点的值均小于它的根结点的值； 
    - 若它的右子树不空，则右子树上所有结点的值均大于它的根结点的值； 它的左、右子树也分别为二叉排序树

2. 若是不理解定义，那就不好解答了
    - **就是理解了题意，也比较绕的**
    - **如何跳过不合法的节点**，直接跳过当前节点，判断next_node....
    - 合法的 cur.left = dfs(cur.left)   cur.right = dfs(cur.right)

3. 此题目有些不好，让我产生了错觉
    - **若是根节点不合法: 以 root.val > R为例，习惯性的去左子树找最大值代替根节点，剪掉根节点的右子树；**
    - 但是这样并未真实的 “剪掉” 不合法的根节点 
    - 非根节点，直接jump掉即可。
    - **为啥有这种错觉** -- 1） 二叉排序树，BST 定义理解不够透彻； 2） 仅注意到了root不合法，忽略了右子树都不合法； 3） 受调整树的影响； 
    - **加强BST的理解 + 画图可解决此问题**

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def trimBST(self, root: TreeNode, L: int, R: int) -> TreeNode:
        if root is None:
            return root 
        
        if root.val > R: ## jump this node, return next node 
            return self.trimBST(root.left, L, R)
        elif root.val < L: 
            return self.trimBST(root.right, L, R) 
        else:
            root.left = self.trimBST(root.left, L, R)
            root.right = self.trimBST(root.right, L, R)
        ## [L, R]
        return root 
```