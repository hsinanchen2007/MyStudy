### 解题思路
我的方法比较无脑，是先copy104题的代码，然后递归实现，不过令我惊讶的是内存排名前列

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
    int re=0;
    
    void preorder(TreeNode*root,int level){
        if(root==NULL)return;
        re=max(re,level);
        
        preorder(root->right,level+1);
        preorder(root->left,level+1);
    }

    int maxlevel(TreeNode*root){
        re=0;
        preorder(root,1);

        return re;
    }

    bool isBalanced(TreeNode* root) {
        if(!root)return 1;
        if(abs( maxlevel( root->right )-maxlevel( root->left ) )>1)return 0;
        return isBalanced(root->right)&&isBalanced(root->left);
    }
};
```
![2020-02-17 21-07-22 的屏幕截图.png](https://pic.leetcode-cn.com/7e11e031fe36662c424cd2445f6ac3045040fd7de4c90e20c513e683cf6534d2-2020-02-17%2021-07-22%20%E7%9A%84%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png)
