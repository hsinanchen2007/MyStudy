### 解题思路
这道题目的思路很简单，就是递归左边，输出中间，递归右边。
我犯了两个错误，一个是递归的时候写的 return 函数  这样递归过程就会提前退出
另一个是没有考虑到空指针。空指针时不能引用。
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
    vector<int> vec; 
    vector<int> inorderTraversal(TreeNode* root) {
        if(root){
            if(root->left){
            inorderTraversal(root->left); 
            }
            vec.push_back(root->val);
            if(root->right){
            inorderTraversal(root->right);  
            }
        }
        return vec;
    }
};
```