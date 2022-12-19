### 解题思路
个人觉得这道题的基本思想和"从二叉搜索树删除结点"一样:
都是基于分类讨论解决局部问题,局部问题得以解决,利用递归就能解决整体问题

注:时间性能应该还能提升
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
class Solution 
{
public:
    void flatten(TreeNode* root) 
    {
        if(!root || (!root->left && !root->right)) return;

        if(root->left && root->right) //1.左右孩子都有
        {
            FindLeftLast(root->left)->right=root->right;
            root->right=root->left;
            root->left=NULL;
        }

        if(root->left && !root->right) //2.只有左孩子
        {
            root->right=root->left;
            root->left=NULL;
        }

        if(!root->left && root->right) //3.只有右孩子,往下递归
            flatten(root->right);
    }

    TreeNode* FindLeftLast(TreeNode* pre)
    {
        while(pre->right) pre=pre->right;
        return pre;
    }
};
```
![image.png](https://pic.leetcode-cn.com/d3f8fbcfe5b7a1a48b80735618ba18cdbd11628af52a26da4322295b0cbee01c-image.png)
