### 解题思路
此处撰写解题思路

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

void InOrder(struct TreeNode* root,int *last_value,int*min){
    int diff;
    if(root==NULL){
        return;
    }
    InOrder(root->left,last_value,min);
    diff = abs((*last_value)- root->val);
    *min = diff<*min?diff:*min;
    *last_value = root->val;
    InOrder(root->right,last_value,min);
}

int getMinimumDifference(struct TreeNode* root){
    int last_value = INT_MAX;
    int min = INT_MAX;
    InOrder(root,&last_value,&min);
    return min;
}
```