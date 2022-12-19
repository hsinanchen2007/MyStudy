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
    void inorder(TreeNode *root,vector<int> &dump)
    {
        if(NULL==root) return;
        inorder(root->left,dump);
        dump.push_back(root->val);
        inorder(root->right,dump);
    }
    int minDiffInBST(TreeNode* root) {
        vector<int>dump;
        inorder(root,dump);
        int min = INT_MAX;
        for(int i=1;i<dump.size();i++)
        {
            if(dump[i]-dump[i-1] < min)
                min=dump[i]-dump[i-1];
        }
        return min;
    }
};
```