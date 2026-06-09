### 解题思路
搜索二叉树的中序遍历是递增序列，判断当前值是否比上一个大即可

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
        //二叉搜索树的中序遍历是递增序列
        long res=LONG_MIN;
        if(!root)return true;
        stack<TreeNode*>sk;
        while(!sk.empty()||root){
             while(root){
                sk.push(root);
                root=root->left;
            }
            root=sk.top();
            if(root->val>res)res=root->val;
            else return false;
            sk.pop();
            root=root->right;
        }
        return true;
    }
};
```