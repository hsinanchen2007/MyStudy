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
    int minDepth(TreeNode* root) {
        if(root==nullptr) return 0;
        int depth=INT_MAX;
        int curTimes=1;
        dfs(depth,root,curTimes);
        return depth;
    }
    void dfs(int &depth,TreeNode* root,int curTimes){
        if(!root){
            return;
        }
        if(root->left==nullptr&&root->right==nullptr){
            if(curTimes<depth) depth=curTimes;
        }
        dfs(depth,root->left,curTimes+1);
        dfs(depth,root->right,curTimes+1);
    }
};
```