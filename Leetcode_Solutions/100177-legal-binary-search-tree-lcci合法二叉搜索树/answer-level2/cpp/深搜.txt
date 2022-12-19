### 解题思路


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
    bool isValidBST(TreeNode* root) {
        if(root == NULL)
            return true;
        if(!flag)
            return false;
        if(root->left && root->left->val < root->val)
        {
            int maxx = root->left->val;
            TreeNode* maxNode = root->left;
            while(maxNode && maxNode->right)
            {
                maxNode = maxNode->right;
                maxx = max(maxx, maxNode->val);
            }
            if(maxx < root->val)
            {
                flag = isValidBST(root->left);
                if(!flag)
                    return false;
            }
            else
                return false;
        }
        else if(root->left)
            return false;
        if(root->right && root->right->val > root->val)
        {
            int minn = root->right->val;
            TreeNode* minNode = root->right;
            while(minNode && minNode->left)
            {
                minNode = minNode->left;
                minn = min(minn, minNode->val);
            }
            if(minn > root->val)
            {
                flag = isValidBST(root->right);
                if(!flag)
                return false;
            }
            else
                return false;
        }
        else if(root->right)
            return false;
        return flag;
    }
private:
    bool flag = true;
};
```