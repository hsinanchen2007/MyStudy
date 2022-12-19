### 解题思路
二叉搜索树的中序遍历即为从小到大排序。可利用这个性质

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
static struct TreeNode** S;
int SLen;

void helper(struct TreeNode* root)
{
    if (root == NULL) {
        return ;
    }
    //printf("%d \n",root->val);
    helper(root->left);
    S[SLen] = root;
    SLen++;
    helper(root->right);
}

struct TreeNode* inorderSuccessor(struct TreeNode* root, struct TreeNode* p) {
    S = (struct TreeNode**)malloc(50000*sizeof(struct TreeNode*));
    helper(root);
    int i;
    for (i = 0; i < SLen; i++) {
        if (S[i] == p) {
            break;
        }
    }
    if (i == SLen-1) {
        return NULL;
    }
    else {
        return S[i+1];
    }
}
```