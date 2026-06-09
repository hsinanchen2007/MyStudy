二叉树，想到递归，平铺直叙就行：
```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int SubNodeVal( struct TreeNode * root);
int sumEvenGrandparent(struct TreeNode* root){
    
    int sum = 0;
    sum = SubNodeVal(root);
    return sum;
}
int SubNodeVal( struct TreeNode * root)
{
    if((root == NULL)){
        return 0;
    }
    
    int temp = 0;
    struct TreeNode* leftroot = root->left;
    struct TreeNode* rightroot = root->right;
    
    if(root->val%2 == 0) {
        if(leftroot != NULL && leftroot->left != NULL){
            temp = leftroot->left->val;
        }
        if(leftroot != NULL && leftroot->right != NULL){
            temp += leftroot->right->val;
        }
        if(rightroot != NULL && rightroot->left != NULL){
            temp += rightroot->left->val;
        }
        if(rightroot != NULL && rightroot->right != NULL){
            temp += rightroot->right->val;
        }   
    }
    temp += SubNodeVal(leftroot);
    temp += SubNodeVal(rightroot);


    return temp;
}
```
