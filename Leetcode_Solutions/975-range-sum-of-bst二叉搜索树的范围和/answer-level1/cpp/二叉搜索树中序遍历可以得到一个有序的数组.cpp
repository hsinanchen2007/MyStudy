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
    vector<int>res;
public:
    int rangeSumBST(TreeNode* root, int L, int R) {
        if(root==NULL) return 0;
        int ans=0;
        DFS(root);
        for(int i=0;i<res.size();i++){
            if(res[i]>=L&&res[i]<=R) ans+=res[i];
        }
        return ans;
    }
    void DFS(TreeNode *root){
        if(root==NULL) return ;
        DFS(root->left);
        res.push_back(root->val);
        DFS(root->right);
    }
};
```