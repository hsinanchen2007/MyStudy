### 解题思路
采用前序遍历+递归求深度判断。
时间会稍微慢一些。
前序遍历：先判断此节点是否符合，再判断左子树和右子树是否满足！

![image.png](https://pic.leetcode-cn.com/ba6fa778737858164b07b424415d46264d0ba35e5d180b2064b78ddf62525b4f-image.png)




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