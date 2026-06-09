### 解题思路
此处撰写解题思路
一个简单的dfs，注意判断BST（优先级最高）和回传BST计算值即可。
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
private:
    int max;
public:
    int sub(TreeNode* root,bool & valid)
    {
        if (!root)   return 0;
        bool lf = true,rt=true;
        int left = sub(root->left,lf);
        int right = sub(root->right,rt);
        if (!rt || !lf)//BST逻辑判断优先
        {
            valid = 0; return -1;
        }
        if (lf && rt && (!root->left || (root->val > root->left->val)) && (!root->right || root->val < root->right->val))
        {
            valid = true;
            if (left + right + root->val > max)    max = left + right + root->val;
            return left + right + root->val;//注意一定要回传值。
        }
        else
        {
            valid = false;
            return 0;//随便return一个值就可以，因为false对于这个分支以及向上所有的父节点都不可用。
        }
    }
    int maxSumBST(TreeNode* root) {
        if (!root)
        {
            return 0;
        }
        max = 0;
        bool p = true;
        sub(root, p);
        return max;
    }
};
```