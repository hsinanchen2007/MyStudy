我们维护两个数组：MaxSum[r]和UpSum[r]，分别表示以r为子树的最大路径和，以r向上的最大路径和
然后我们只需要遍历一遍树，求出每个点的 MaxSum+UpSum，再取最大就好了。

递推方程：
MaxSum[r] = max(max(MaxSum[r->left],MaxSum[r->right]) + r->val,0)
UpSum[r->left] = max(r->val+MaxSum[r->right],r->val+Upsum[r],0)
```c++ []
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    map<TreeNode*,int> maxSum;
    map<TreeNode*,int> upSum;
    int ans = -2147483648;
    void dp_up(TreeNode* r){
        maxSum[r] = r->val;
        if(r->left == NULL && r->right == NULL){
            return;
        }
        if(r->left) dp_up(r->left);
        if(r->right) dp_up(r->right);
        int tmp = max(maxSum[r->left],maxSum[r->right]);
        maxSum[r] = max(maxSum[r],maxSum[r]+tmp);
    }
    void dp_down(TreeNode* r){
        if(r->left == NULL && r->right == NULL){
            return;
        }
        if(r->left){
            int tmp = max(r->val + (r->right == NULL ? 0 : maxSum[r->right]),
                                 r->val + upSum[r]) ;
            upSum[r->left] = max(upSum[r->left],upSum[r->left] + tmp);
            dp_down(r->left);  
        }
        if(r->right){
            int tmp = max(r->val + (r->left == NULL ? 0 : maxSum[r->left]),
                                  r->val + upSum[r]);
            upSum[r->right] = max(upSum[r->right],upSum[r->right] + tmp);
            dp_down(r->right);
        }
    }
    void dfs(TreeNode* r){
        if(r->left == NULL && r->right == NULL){
            ans = max(ans,maxSum[r]+upSum[r]);
            //ans = max(ans,r->val+upSum[r]);
            return;
        }
        ans = max(ans,maxSum[r]+upSum[r]);
        //ans = max(ans,r->val+upSum[r]);
        if(r->left) dfs(r->left);
        if(r->right) dfs(r->right);
    }
    int maxPathSum(TreeNode* root) {
        dp_up(root);
        dp_down(root);
        dfs(root);
        return ans;
    }
};
```


         