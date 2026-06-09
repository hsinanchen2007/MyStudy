# 思路：
1）创建格外的递归方程，其中包含递归过nodes值的和的指针
2）并且在递归过程中逐渐重写每一个node的数值（其实就是 常规 BSTtraverse 递归的通用的模板）

# 代码：
```
struct TreeNode* privatebstToGst(struct TreeNode* root, int *total_value){
   if(root == NULL) {
       return NULL;
   }
    root->right = privatebstToGst(root->right, total_value);
    root->val = (*total_value = root->val + *total_value);
    root->left = privatebstToGst(root->left, total_value);
    return root;
}


struct TreeNode* bstToGst(struct TreeNode* root){
    int total_value = 0;
    return privatebstToGst(root, &total_value);
}

```
