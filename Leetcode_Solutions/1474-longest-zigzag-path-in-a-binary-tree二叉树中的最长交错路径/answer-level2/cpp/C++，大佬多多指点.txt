时间复杂度：勉强200ms,空间：近100MB,希望大家指点如何优化。
思路：递归，通过LR标记方向，每遍历完一条路时，换个方向，重新遍历。
```
class Solution {
public:
    int ans=0;
    int longestZigZag(TreeNode* root) {
        dfs(root->left,1,1);
        dfs(root->right,0,1);
        if(!root->left&&!root->right)
        return 0;
        return ans-1;
    }
    void dfs(TreeNode*root,int LR,int len){
        if(!root){
            ans=max(len,ans);
            return;
        }
        if(LR==1){
            dfs(root->right,0,len+1);//若当前路遍历完。
            dfs(root->left,1,1);//换个方向，重新遍历。
        }
        else{
            dfs(root->left,1,len+1);
            dfs(root->right,0,1);
        }
    }
};
```
