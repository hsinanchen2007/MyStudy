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
class Solution {
private:
    TreeNode* helper(vector<int>& nums,int L,int R){
        if(L > R) return NULL;
        int mid = L + R >> 1;
        int root_val = nums[mid];
        TreeNode* root = new TreeNode(root_val);
        root->left = helper(nums,L,mid - 1);
        root->right = helper(nums,mid + 1,R);
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums,0,nums.size() - 1);
    }
};
```