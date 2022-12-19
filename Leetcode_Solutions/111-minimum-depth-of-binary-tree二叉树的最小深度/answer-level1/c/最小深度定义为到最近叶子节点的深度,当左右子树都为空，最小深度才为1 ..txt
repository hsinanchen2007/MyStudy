### 解题思路
最小深度定义为到最近叶子节点的深度,当左右子树都为空，最小深度才为1 .
BFS 搞定

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

 int BFS(struct TreeNode* root, int minDepth)
 {
     if (root == NULL) {
         return minDepth;
     }
     int leftDepth = BFS(root->left, minDepth + 1);
     int rightDepth = BFS(root->right, minDepth + 1);

     if (root->left == NULL || root->right== NULL) {
         return ((leftDepth > rightDepth) ? leftDepth : rightDepth);
     }

     return ((leftDepth > rightDepth) ? rightDepth : leftDepth);

 }


int minDepth(struct TreeNode* root){
    int minDepth = 0;    
    return BFS(root, minDepth);
}
```
执行用时 :
8 ms
, 在所有 C 提交中击败了
90.74%
的用户
内存消耗 :
9.8 MB
, 在所有 C 提交中击败了
83.24%
的用户