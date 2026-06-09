```
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
    TreeNode *sort_binary(vector<int>&nums,int l,int r){
        if(l  > r) return NULL;
        TreeNode * root = new TreeNode;
        root->val = nums[(l + r)/2];
        root->left = sort_binary(nums,l,(l + r)/2 - 1);
        root->right = sort_binary(nums,(l + r)/2 + 1,r);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
       TreeNode * root;
        root = sort_binary(nums,0,nums.size()-1);
        return root;
    }

};
```
有没有大佬证明一下为什么中间的值是根