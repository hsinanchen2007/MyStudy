```
typedef struct Result{
    int height=0;
    bool bal=false;
}Result;
class Solution {
public:
    Result helper(TreeNode* root){
        Result rt=Result();
        if(root==NULL){
            rt.bal=true;
            return rt;
        }
        Result left=helper(root->left);
        Result right=helper(root->right);
        rt.height=max(left.height,right.height)+1;
        if(!left.bal||!right.bal){//左右子树有一个不符合要求直接返回完事
            rt.bal=false;
            return rt;//直接结束吧，不需要再遍历了。。。
        }
        if(abs(left.height-right.height)<=1){//判断是否平衡。。。即左右子树高度差值是否小于1.
            rt.bal=true;
            return rt;
        }else{
            rt.bal=false;
            return rt;
        }
    }
    bool isBalanced(TreeNode* root) {
        return helper(root).bal;
    }
};
```
