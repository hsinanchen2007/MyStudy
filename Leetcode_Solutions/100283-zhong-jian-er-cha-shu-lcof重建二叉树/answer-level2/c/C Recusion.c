### 解题思路
1. 根据前序遍历和中序遍历的特点，可以知道父节点和左右孩子
2. 递归求解即可

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
typedef struct TreeNode Node;

Node* create(int* preorder, int* inorder, int preL, int preR, int inL, int inR) {
    if(preL > preR)
        return NULL;

    Node* root = (Node*)malloc(sizeof(Node));

    root->val = preorder[preL];
    int k;
    for(int i = inL; i <= inR; ++i) {
        if(inorder[i] == preorder[preL]){
            k = i;
            break;
        }
    }
    int num_Left = k - inL;

    root->left  = create(preorder, inorder, preL + 1, preL + num_Left, inL, k - 1);
    root->right = create(preorder, inorder, preL + num_Left + 1, preR, k + 1, inR);
    return root;
}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize){
    
    return create(preorder, inorder, 0, preorderSize - 1, 0 ,inorderSize - 1);
}
```