### 解题思路
1、判断左子树是否为空，若为空则直接往右走，若不为空则2
2、将当前节点root的右子树接到当前root节点的左孩子节点的最右下边的孩子节点
3、将当前节点root的左子树接到右子树上，并将左节点置为NULL。

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
    void flatten(TreeNode* root) {
        if(root==NULL) return;
        while(root!=NULL)
        {
            if(root->left!=NULL)
            {
                TreeNode* tp=root->left;
                while(tp->right!=NULL)
                    tp=tp->right;
                tp->right=root->right;
                root->right=root->left;
                root->left=NULL;
            }
            root=root->right;
        }
    }
};
```