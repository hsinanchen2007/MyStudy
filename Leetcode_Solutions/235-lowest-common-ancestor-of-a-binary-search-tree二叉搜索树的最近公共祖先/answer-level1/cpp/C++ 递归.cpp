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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //根据值大小，判断左右子树，进行递归
        int num1=p->val;
        int num2=q->val;
        int mid=root->val;
        if(num1<mid&& num2<mid){
            return lowestCommonAncestor(root->left,p,q);
        }
        if(num1>mid&&num2>mid){
            return lowestCommonAncestor(root->right,p,q);
        }
        return root;
    }
};
```