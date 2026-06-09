1. 二分数组，根节点指向中间元素，二分后的子数组递归调用函数
2. 重复上述步骤，直到数组元素数量小于2；
3. 若子数组大小为0，则返回NULL；若子数组元素为1，则返回val=数组元素的节点
``` C++
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.empty())
            return NULL;        
        int len=nums.size();
        return helper(nums,0,len);
    }
    
    TreeNode* helper(vector<int>& nums,int f,int s)
    {
        if(s==f) return NULL;
        int mid=(s+f)/2;
        TreeNode* root=new TreeNode(nums[mid]);
        if(f-s==1) return root;     
        root->left=helper(nums,f,mid);
        root->right=helper(nums,mid+1,s);
        return root;
    }
};
```