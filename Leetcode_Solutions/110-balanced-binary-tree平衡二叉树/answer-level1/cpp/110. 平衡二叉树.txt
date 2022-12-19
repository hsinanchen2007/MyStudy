### 解题思路
直接计算高度，可能代码更清晰
再做一个标记
执行用时 :16 ms, 在所有 C++ 提交中击败了73.56%的用户
感觉还可以
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
    int f=0;
    int dfs(TreeNode* root){
        if(root==NULL) return 0;
        int l=dfs(root->left);
        int r=dfs(root->right);
        if(abs(l-r)>1) f=1;
        return max(l,r)+1; 
    }
    bool isBalanced(TreeNode* root) {
        dfs(root);
        if(f) return false;
        else return true;
    }
};
```