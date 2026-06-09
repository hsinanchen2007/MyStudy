### 解题思路
中序遍历，记录顺序，返回第k个

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
    int res;
    int count=0;
    int kthSmallest(TreeNode* root, int k) {
        dfs(root,k);
        return res;
    }
    void dfs(TreeNode* root,int k){
        if(root==NULL) return;
        dfs(root->left,k);
        count++;
        if(count==k) res=root->val;
        dfs(root->right,k);
    }
};
```