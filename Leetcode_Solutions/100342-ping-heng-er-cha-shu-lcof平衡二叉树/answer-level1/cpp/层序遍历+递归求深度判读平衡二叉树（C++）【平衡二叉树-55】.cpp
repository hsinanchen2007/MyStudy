### 解题思路
利用**非递归的层序遍历+递归方法求树的深度**实现。
- 层序遍历各个节点
- 然后把每个节点的左右子树带入求深度的函数
- 若两者之差大于1，就返回false；否则，true

这种方法比前序遍历+递归求深度稍微快一些，不知道为什么//

![image.png](https://pic.leetcode-cn.com/cb1ceb544049d9bb7725c613f73ac06e86e45a9a3951de9c879291291dbc04a5-image.png)


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
    bool isBalanced(TreeNode* root) {
        if(!root)  return true;
        queue<TreeNode*>que;
        que.push(root);
        TreeNode *t=root;
        while(!que.empty()){
            TreeNode *t=que.front();
            que.pop();
            int right=0,left=0;
            if(t->left){
                que.push(t->left);
                left=help(t->left);
            }
            if(t->right){
                que.push(t->right);
                right=help(t->right);
            }
            if(left-right>1||left-right<-1)  return false;
        }
        return true;

    }

    int help(TreeNode *root){
        if(root==NULL)  return 0;
        int left=help(root->left);
        int right=help(root->right);
        return 1+(left>right?left:right);
    }
};
```