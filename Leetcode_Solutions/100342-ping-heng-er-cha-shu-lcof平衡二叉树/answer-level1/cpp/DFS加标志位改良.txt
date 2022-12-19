在DFS的基础上，加入一个标志位，此标志位优先判断，若在递归的过程中遇到一次false的情况，那么它会永远为false，在之后的递归过程中优先判断flag为false，即不再执行后面的递归过程，直接层层返回，节省不必要的时间。

```
class Solution {
public:
    Solution(){flag=true;}
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        flag=flag&&isBalanced(root->left)&&isBalanced(root->right)&&(abs(height(root->left)-height(root->right))<=1);
        return flag;
    }
    int height(TreeNode* root)
    {
        if(!root) return 0;
        return max(height(root->left),height(root->right))+1;
    }
private:
    bool flag;
};
```
