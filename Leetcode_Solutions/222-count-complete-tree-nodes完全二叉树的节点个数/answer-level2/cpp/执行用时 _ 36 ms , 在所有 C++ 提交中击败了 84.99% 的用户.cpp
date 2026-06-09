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
    void DFs(TreeNode*root, int&num)
    {
        if(root == nullptr)
        {
            --num;
            return;
        }
        DFs(root->left, ++num);
        DFs(root->right, ++num);
    }
    int countNodes(TreeNode* root) 
    {
        int sum = 1;
        DFs(root,sum);
        return sum;
    }
};
```