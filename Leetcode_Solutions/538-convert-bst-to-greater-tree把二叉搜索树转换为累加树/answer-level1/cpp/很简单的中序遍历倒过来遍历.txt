### 解题思路
按题目的意思访问顺序变为：right->root->left
只不过每一次访问过后，结点值要加上之前访问过的所有结点值。
之前一直考虑，函数怎么传这个累加的值作为参数的问题，实际上把它设成全局变量就可以了。

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
    int sum = 0;
    //当函数的某个参数无法传下去的时候，思考全局变量
    TreeNode* convertBST(TreeNode* root) {
        if(root != nullptr){
    //obviously traversal sequence is right->root->left
           convertBST(root->right);
           root->val += sum;
           sum = root->val;
           convertBST(root->left);
           return root;
        }
         return nullptr;
    }
};
```