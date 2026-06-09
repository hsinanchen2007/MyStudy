### 解题思路
思路很简单，就是将结果分为三类：
1.p,q同属于左子树
2.p,q同属于右子树
3.p,q分别属于左子树和右子树

递归查找p,q所属的子树

### 代码

```cpp
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
        if(root == NULL) //两个节点均不属于这棵子树
            return NULL;
        if(p == root || q == root) // p属于这个子树，或者q属于这个子树
            return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q); //判断p q 是否同属于左子树
        TreeNode* right = lowestCommonAncestor(root->right, p, q); //判断p q 是否同属于右子树

        if(left != NULL && right != NULL) // 说明一个属于左子树，一个属于右子树
            return root; //则返回根节点
        
        return left != NULL ? left : right; // 如果哪个子树不为NULL则两个节点均属于那个子树
    }
};
```