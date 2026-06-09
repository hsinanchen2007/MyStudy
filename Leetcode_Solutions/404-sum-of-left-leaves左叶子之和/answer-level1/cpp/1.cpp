### 解题思路
1.遍历二叉树，每次遍历传入是否是左节点
2.判断当前节点时左节点，并且是叶子节点，累计val值
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
    void traverseTree(TreeNode* root, bool bl)
    {
        if (root == NULL)
            return;
        if (bl && root->left == NULL && root->right == NULL)
            m_sum += root->val;
        traverseTree(root->left, true);
        traverseTree(root->right, false);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        //遍历二叉树，是左叶子便将值累计
        traverseTree(root, false);
        return m_sum;
    }
private:
    int m_sum;
};
```