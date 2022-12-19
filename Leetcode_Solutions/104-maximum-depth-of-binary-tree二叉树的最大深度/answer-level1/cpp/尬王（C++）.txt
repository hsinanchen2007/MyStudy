```
class Solution {
public:
int maxDepth(TreeNode* root) {
int a,b;
if(root == NULL){return 0;}//如果树上无结点，返回0
else if(root->left==NULL&&root->right==NULL){return 1;}//当前如果只有根结点，返回1
else
{
a = maxDepth(root->left);//左子结点
b = maxDepth(root->right);//右子结点
}
if(a>=b){return a+1;}//判断左右子结点返回值的大小，取大数加一并返回
else{return b+1;}
}
};
```
