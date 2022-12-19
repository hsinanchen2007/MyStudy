### 解题思路
每次将数组平均分成两份，中间的数作为每次的根结点

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
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return tree(nums,0,nums.size()-1);
    }
    TreeNode* tree(vector<int>&nums,int left,int right)
    {
        if(left>right)
        {
            return NULL;
        }
        int mid=(left+right)/2;
        TreeNode* node=new TreeNode(nums[mid]);
        node->left=tree(nums,left,mid-1);
        node->right=tree(nums,mid+1,right);
        return node;
    }
};
```