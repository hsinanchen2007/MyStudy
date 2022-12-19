
如果：sum = 0
![QQ截图20190626143558.png](https://pic.leetcode-cn.com/72defb08c4ca98305ab4235d4799d51ca050ec36defc2f9807b580a24f5b9b17-QQ%E6%88%AA%E5%9B%BE20190626143558.png)


```
int pathSum(struct TreeNode* root, int sum){
    return find_val(root, sum);
}

int find_val(struct TreeNode* root, int sum){
    if (root == NULL) return 0;
    
    return find_node(root, sum) + 
           find_val(root->left, sum) + 
           find_val(root->right, sum);
}

int find_node(struct TreeNode* root, int sub){
    if (root == NULL) return 0;
    if (sub - root->val == 0) {
        return 1 +  //防止出现连续的情况
               find_node(root->left, sub - root->val) + 
               find_node(root->right, sub - root->val);
    }else{
        return find_node(root->left, sub - root->val) + 
               find_node(root->right, sub - root->val);
    }
}
```
