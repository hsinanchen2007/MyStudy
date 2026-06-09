### 解题思路
因为二叉搜索树，所以可以利用二叉搜索树的特性，左节点的值小于根节点，右节点的值大于根节点。那么给定一个target值，就首先与根进行比较，如果其值比根大，就进入右子树，如果小，进入左子树，进行递归运算。
其中比较坑的点在于，要注意进入的子树不能为空子树，如果root为NULL 会出现空指针异常
### 代码

```cpp
class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        if(root->left ==NULL && root->right ==NULL)
        {
            return root->val;
        }
        if(root->val > target && root->left)
        {   
            return (abs(root->val-target) < abs(closestValue(root->left, target)-target)?root->val:closestValue(root->left, target)) ;
        }
        else if(root->val < target && root->right){
            
            return (abs(root->val-target) < abs(closestValue(root->right, target)-target)?root->val:closestValue(root->right, target)) ;
        }
        else{
            return root->val;
        }
    }
};
```