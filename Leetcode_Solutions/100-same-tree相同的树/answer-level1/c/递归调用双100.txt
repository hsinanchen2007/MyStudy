### 解题思路
此处撰写解题思路
如果节点为空，返回true；如果节点值相同且节点为叶子节点返回true，否则返回左节点结果 && 右节点结果
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


bool isSameTree(struct TreeNode* p, struct TreeNode* q){
    if(NULL == p && q == NULL){
        return true;
    }
    
    while(p && q){
        if(p->val == q->val){
            if(p->left == NULL && p->right == NULL && q->left == NULL && q->right == NULL){
                return true;
            }
            return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
        }else{
            break;
        }
    }

    return false;
}
```