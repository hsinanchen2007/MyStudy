
## 是时候总结一波了
### 1. 遍历所有节点
```c++
int sumOfLeftLeaves(TreeNode* root) {
    if(!root) return 0;
    return root->val + sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
}    
```

### 2. 遍历所有叶子节点
```c++
int sumOfLeftLeaves(TreeNode* root) {
    if(!root) return 0;
    if(!root->left && !root->right){
        return root->val;
    }
    return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
}
```

### 3. 遍历所有左叶子节点

#### 3.1 方法1
> 使用一个bool变量，使得只有在访问左子树的时候才记录叶子节点；这样就能将左右叶子节点区分开了。

```c++
int sumOfLeftLeaves(TreeNode* root) {
    return dfs(root, false);
}

int dfs(TreeNode* root, bool isLeftNode){
    if(!root) return 0;
    if(isLeftNode && !root->left && !root->right){
        return root->val;
    }else{
        int left = dfs(root->left, true);
        int right = dfs(root->right, false);
        return left+right;
    }
}
```

#### 3.2 方法2
```c++
int sum = 0;

int sumOfLeftLeaves(TreeNode* root) {
    helper(root);
    return sum; 
}

void helper(TreeNode* root){
    if(!root) return;
    if(root->left!=nullptr && !root->left->left && !root->left->right){
        sum += root->left->val;
    }
    helper(root->left);
    helper(root->right);
}
```