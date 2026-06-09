### 解题思路
先遍历，如果当前根结点等于目标值，从它的左结点开始一直往右走，找到最大值以后跟右结点连接，再把根结点设置为左结点，最后依次往回把处理好的子树交给根就可以了。

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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL)
            return root;
        if(root->val == key)
        {
            if(root->left)
            {
                TreeNode* last = root->left;
                while(last && last->right)
                    last = last->right;
                last->right = root->right;
                root = root->left;
            }
            else
                root = root->right;
        }
        else if(root->val < key)
            root->right = deleteNode(root->right, key);
        else
            root->left = deleteNode(root->left, key);
        return root;
    }
};
```