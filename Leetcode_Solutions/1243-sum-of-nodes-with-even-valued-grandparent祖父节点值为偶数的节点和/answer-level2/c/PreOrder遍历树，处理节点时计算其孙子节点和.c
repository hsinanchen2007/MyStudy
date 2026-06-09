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

typedef struct TreeNode *PtrNode; 

#define MAX_NODE_NUM 100000
int Cal(PtrNode node) {

    int subSum = 0;

    if (node == NULL)
    {
        return 0;/* code */
    }
    if (node->left != NULL)
    {
        if (node->left->left != NULL)
        {
            subSum += node->left->left->val;
        }
        if (node->left->right != NULL)
        {
            subSum += node->left->right->val;
        }    
        
    }
    
    if (node->right != NULL)
    {
        if (node->right->left != NULL)
        {
            subSum += node->right->left->val;
        }
        if (node->right->right != NULL)
        {
            subSum += node->right->right->val;
        }    
        
    }

    return subSum;
}

int preOrder(PtrNode root) {
    int sum = 0;
    if (root == NULL)
    {
        return 0;
    }
    if (root->val % 2 == 0)
    {
       sum = Cal(root);
    }
    sum += preOrder(root->left);
    sum += preOrder(root->right);
    return sum;
}


int sumEvenGrandparent(struct TreeNode* root){
    int sum;
    sum = preOrder(root);
    return sum;
}
```