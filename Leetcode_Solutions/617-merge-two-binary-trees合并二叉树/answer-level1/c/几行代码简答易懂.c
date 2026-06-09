### 解题思路
执行用时 :
28 ms
, 在所有 C 提交中击败了
95.65%
的用户
内存消耗 :
14.5 MB
, 在所有 C 提交中击败了
100.00%
的用户

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


struct TreeNode* mergeTrees(struct TreeNode* t1, struct TreeNode* t2){
    if(t1==NULL) return t2;
    if(t2==NULL) return t1;
    t1->val+=t2->val;
    t1->left=mergeTrees(t1->left,t2->left);
    t1->right=mergeTrees(t1->right,t2->right);
    return t1;

    

}

```