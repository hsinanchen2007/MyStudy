一开始的思路是层序遍历，遍历每一个结点，将每一个结点作为起点判断是否是二叉搜索树，然后根据二叉搜索树性质：中序遍历是有序的，进行判断。。
但是很可惜：超时，数据太大就出现超时了。。。但是个人觉得层序遍历的方法，正常人都很容易想到的，，，
之后，没办法，使用B站小姐姐的树模板。。。很快就能解决啦。。。

模板来源：https://www.bilibili.com/video/av92328487
```
typedef struct Result{
    bool isBal=false;
    //int height=0;
    int min_num=INT_MAX;
    int max_num=INT_MIN;
    int sum=0;
}Result;

class Solution {
public:
    int ans=0;
    Result dfs(TreeNode* root){
        Result rt=Result();
        if(!root){
            rt.isBal=true;
            return rt;
        }
        Result left=dfs(root->left);
        Result right=dfs(root->right);
        
        if(!left.isBal||!right.isBal){//左右有一个不是二叉搜索树的话，直接结束。。。
            rt.isBal=false;
            return rt;
        }
        if(root->val>left.max_num&&root->val<right.min_num){
            rt.isBal=true;
            rt.sum=root->val+left.sum+right.sum;
            ans=max(ans,rt.sum);
            //cout<<ans<<endl;
            //下面更新一下当前结点的最大值
            rt.min_num=min(left.min_num,root->val);
            rt.max_num=max(right.max_num,root->val);
        }else{
            rt.isBal=false;
            //rt.sum=0;
        }
        return rt;
        
    }
    int maxSumBST(TreeNode* root) {
        //ans=0;
        dfs(root);
        return ans;
    }
};
```
