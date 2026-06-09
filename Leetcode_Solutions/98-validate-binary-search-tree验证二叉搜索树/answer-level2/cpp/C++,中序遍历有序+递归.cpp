解法一：中序遍历有序
```
class Solution {
public:
//中序遍历递增有序即可
    void dfs(TreeNode* root,vector<int>&ans){
        if(root==NULL)return;
        dfs(root->left,ans);
        ans.push_back(root->val);
        dfs(root->right,ans);
    }
    bool isValidBST(TreeNode* root) {
        vector<int>ans;
        dfs(root,ans);
        for(int i=1;i<ans.size();i++){
            if(ans[i]<=ans[i-1])return false;
        }
        return true;
    }
};
```
解法二：递归+后序遍历+结构体：
```
typedef struct Result{
    bool isValid=false;
    long min_num=LONG_MAX;
    long max_num=LONG_MIN;//每一个分支存在最大数与最小数值。。。在当前结点记录一下整个分支的最大值最小值。
}Result;
class Solution {
public:
    Result solve(TreeNode* root){
        Result rt=Result();
        if(root==NULL){
            rt.isValid=true;
            return rt;
        }
        Result left=solve(root->left);
        Result right=solve(root->right);
        if(!left.isValid||!right.isValid){
            rt.isValid=false;
            return rt;
        }//只要出现不满足条件的直接返回false。
        //访问下面代码表示上面的if已经满足了，即左右子树是二叉搜索树，所以现在只要确定一下当前结点与左右子树的大小比较
        if(root->val<=left.max_num||root->val>=right.min_num){
            rt.isValid=false;

        }else{
            rt.isValid=true;
            rt.min_num=min((long)root->val,left.min_num);
            rt.max_num=max((long)root->val,right.max_num);
        }
        return rt;
    }
    bool isValidBST(TreeNode* root) {
        return solve(root).isValid;
    }
};
```

