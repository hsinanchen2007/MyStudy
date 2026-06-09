### 解题思路
此处撰写解题思路

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
    TreeNode* deleteNode(TreeNode* root, int key) 
    {
        Remove(root,key);
        return root;
    }
    void Remove(TreeNode*& root, int key)
    {
        if(root == nullptr)
        {
            return;
        }
        if(key < root->val)
            Remove(root->left,key);
        else if(key > root->val)
            Remove(root->right,key);
        else if(root->left != nullptr && root->right != nullptr)
        {
            root->val = findMin(root->right)->val;
            Remove(root->right,root->val);
        }
        else
        {
            TreeNode*oldNode = root;
		    root = (root->left != nullptr) ? root->left : root->right; //如果有儿子，就让儿子接上，如果没有那t就设置为nullptr
		    delete oldNode;
        }
    }
    TreeNode *findMin(TreeNode * t) 
    {
        if (t != nullptr)
            while (t->left != nullptr)
                t = t->left;
         return t;
    }


};



```