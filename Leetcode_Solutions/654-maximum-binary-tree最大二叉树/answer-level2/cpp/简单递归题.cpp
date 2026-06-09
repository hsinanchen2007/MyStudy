- 简单递归题
```c++
class Solution {
public:
    int n;
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        n = nums.size();
        return dfs(nums,0,n-1);
    }
    TreeNode* dfs(vector<int>& nums,int start,int end){
        if(start > end)return NULL;
        int maxn = start;
        for(int i=start;i<=end;i++){
            if(nums[maxn] < nums[i])maxn = i;
        }
        int len = maxn - start;
        TreeNode* node = new TreeNode(nums[maxn]);
        node->left = dfs(nums,start,start+len-1);
        node->right = dfs(nums,start+len+1,end);
        return node;
    }
};
```
