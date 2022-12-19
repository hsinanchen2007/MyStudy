求树高的题的变形吧算是。思路就是递归，先找出左子树最大值，然后右子树最大值，最后更新最大值即可
```
class Solution {
public:
    int helper(TreeNode* root,int& value){
//递归中止条件
        if(root==nullptr){
            return 0;
        }
//寻找左子树最大值
        int left=helper(root->left,value);
//寻找右子树最大值
        int right=helper(root->right,value);
//更新最大值
        value=max(value,root->val+left+right);
//如果是一个负数，那么对结果只有坏处没有好处，所以如果是负数的话，抛弃他
        return max(0,max(left,right)+root->val);
    }
    int maxPathSum(TreeNode* root) {
        int _max=INT_MIN;
        helper(root,_max);
        return _max;
    }
};
```
