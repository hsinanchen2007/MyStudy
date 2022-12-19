### 解题思路
使用先序遍历和标识符操作

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
    int sumOfLeftLeaves(TreeNode* root) {
        zuo(root,0);
        return sum;
    }
    void zuo(TreeNode* root,char flag){
        if(root == NULL){
            return;
        }
        root->val;
        if(root->left==NULL&&root->right==NULL&&flag==1){
            sum += root->val;
        }
        zuo(root->left,1);
        zuo(root->right,2);
    }
};
```