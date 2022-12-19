### 解题思路
LCA出现的位置只可能有三种, 使用divide & conquer求解：
1. 左子树
2. 右子树
3. 跨接左右子树

### 代码

```java []
class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if(root == null || root == p || root == q)
            return root;

        TreeNode resL = lowestCommonAncestor(root.left, p, q);
        TreeNode resR = lowestCommonAncestor(root.right, p, q);

        if(resL != null && resR != null)
            return root;

        if(resL != null)
            return resL;

        if(resR != null)
            return resR;

        return null;
    }
}
```
```python []
class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        if root == None or root == p or root == q:
            return root

        resL = self.lowestCommonAncestor(root.left, p, q)
        resR = self.lowestCommonAncestor(root.right, p, q)

        if resL != None and resR != None:
            return root

        if resL != None:
            return resL

        if resR != None:
            return resR

        return None
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // LCA问题
        if(root == nullptr || root==p || root == q)
            return root;

        // divide
        TreeNode *resL = lowestCommonAncestor(root->left, p, q);
        TreeNode *resR = lowestCommonAncestor(root->right, p, q);

        // merge
        if(resL != nullptr && resR != nullptr)
            return root;

        if(resL != nullptr)
            return resL;

        if(resR != nullptr)
            return resR;

        return nullptr;

    }
};
```