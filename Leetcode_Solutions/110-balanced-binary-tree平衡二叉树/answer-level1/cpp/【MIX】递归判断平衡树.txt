### 解题思路
自顶向下方法, 当前节点&左子树&右子树均为平衡树时, 返回true, 但是存在冗余判定

### 代码

```java []
class Solution {
    public boolean isBalanced(TreeNode root) {
        // 子树是否为不平衡树即可
        return maxDepth(root) != NOT_BAL;
    }

    private int maxDepth(TreeNode node){
        if(node == null)
            return 0;

        int depL = maxDepth(node.left);
        int depR = maxDepth(node.right);

        // 如果是不平衡树则返回不平衡标识
        if(depL == NOT_BAL || depR == NOT_BAL || Math.abs(depL-depR)>1)
            return NOT_BAL;

        // 如果是平衡树则返回节点的高度
        return Math.max(depL, depR)+1;
    }

    // 定义不平衡标识
    private int NOT_BAL = -1;
}
```
```python []
class Solution:
    def __init__(self):
        self.NOT_BAL = -1

    def isBalanced(self, root: TreeNode) -> bool:
        return self.getMaxDepth(root) != self.NOT_BAL

    def getMaxDepth(self, node):
        if node == None:
            return 0
        
        depL = self.getMaxDepth(node.left)
        depR = self.getMaxDepth(node.right)

        if depL == self.NOT_BAL or depR == self.NOT_BAL or abs(depL-depR)>1:
            return self.NOT_BAL

        return max(depL, depR)+1
```
```c++ []
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(root == nullptr)
            return true;

        return abs(getHeight(root->left)-getHeight(root->right))<=1 && isBalanced(root->left) && isBalanced(root->right);
    }

    // 计算高度
    int getHeight(TreeNode *node){
        if(node == nullptr)
            return 0;
        return 1+max(getHeight(node->left), getHeight(node->right));
    }
};
```