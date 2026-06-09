### 解题思路
此处撰写解题思路

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
       return build(nums,0,nums.size()-1);
    }
    TreeNode* build(vector<int>& nums,int l,int r)
    {
        if(l>r) return NULL;
        int mid=l+((r-l)>>1);
        TreeNode*node=new TreeNode(nums[mid]);
        node->left=build(nums,l,mid-1);
        node->right=build(nums,mid+1,r);
        return node;
    }
};
```