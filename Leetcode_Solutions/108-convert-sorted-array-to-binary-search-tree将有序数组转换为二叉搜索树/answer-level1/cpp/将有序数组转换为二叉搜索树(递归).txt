### 解题思路

### 代码

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution 
{
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) 
    {
        if(nums.empty()) return NULL;
        return BuildAVL(nums,0,nums.size()-1);
    }

    TreeNode* BuildAVL(vector<int>& nums,int low,int high)
    {
        int mid=(low+high)/2;
        
        TreeNode* root=new TreeNode(nums[mid]);
        if(mid-1>=low) root->left=BuildAVL(nums,low,mid-1);
        if(high>=mid+1) root->right=BuildAVL(nums,mid+1,high);

        return root;
    }
};
```