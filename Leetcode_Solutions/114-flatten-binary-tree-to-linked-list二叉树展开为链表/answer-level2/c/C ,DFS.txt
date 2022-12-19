### 解题思路
执行用时 :8 ms, 在所有 C 提交中击败了61.40%的用户内存消耗 :6.4 MB, 在所有 C 提交中击败了100.00%的用户

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


void flatten(struct TreeNode* root){
    if(root ==NULL)
        return ;
    struct TreeNode* tmp_node =malloc(sizeof(struct TreeNode));
    struct TreeNode* tmp_node1 =malloc(sizeof(struct TreeNode));
    tmp_node = root->right ;
    flatten(root->left);
    flatten(root->right);
    root->right = root->left;
    root->left = NULL;
    tmp_node1 =root;
    while(tmp_node1->right != NULL){
        tmp_node1 =tmp_node1->right ;
    }
    tmp_node1->right = tmp_node;

}
```