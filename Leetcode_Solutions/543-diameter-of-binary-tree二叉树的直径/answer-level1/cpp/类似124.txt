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
        
    int diameterOfBinaryTree(TreeNode* root) {
        maxdiameterofTree(root);
        return res;
    }
private:
    int res = 0;
    int maxdiameterofTree(TreeNode* root)
    {
        if(!root)
            return 0;
        int left = maxdiameterofTree(root->left);
        int right = maxdiameterofTree(root->right);
        res = max(res,left+right);
        return max(left,right)+1;
    }
};
```