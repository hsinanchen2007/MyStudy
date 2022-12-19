
```
#define MAXSIZE  (100)
void getTreeLeaf(struct TreeNode* root, int leaf[], int* index)
{
    if (root == NULL) {
        return; 
    }
    
    if ((root->left == NULL) && (root->right == NULL)) {
        leaf[*index] = root->val;
        *index = *index + 1;
        return;
    }
    
    getTreeLeaf(root->left, leaf, index);
    getTreeLeaf(root->right, leaf, index);
    return;    
}

bool leafSimilar(struct TreeNode* root1, struct TreeNode* root2){
    int leafNum1, leafNum2;
    int leaf1[MAXSIZE], leaf2[MAXSIZE];
    
    leafNum1 = leafNum2 = 0;
    getTreeLeaf(root1, leaf1, &leafNum1);
    getTreeLeaf(root2, leaf2, &leafNum2);
    
    if (leafNum1 != leafNum2) {
        return false;
    } else {
        while(leafNum1-- > 0) {
            if (leaf1[leafNum1] != leaf2[leafNum1]) {
                return false;
            }
        }
    }
    
    return true;

}
```

