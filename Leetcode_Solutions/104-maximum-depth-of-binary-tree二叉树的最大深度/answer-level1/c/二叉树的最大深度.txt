### 解题思路
树 —— 递归
递归还是没掌握好

### 代码

```c
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int maxDepth(struct TreeNode* root){
    if(!root) return 0;
    //if(!root->left && !root->right) return 1; // 注意是 && ,这句可省略
    int lt = maxDepth(root->left), rt = maxDepth(root->right);
    lt = lt > rt ? lt : rt;
    return 1+ lt; 
}
```
JAVA
![image.png](https://pic.leetcode-cn.com/4bc11b210c2ccdeb8c894d071316e7476525b15dae40e9a8426e6eae4b13d3fb-image.png)

