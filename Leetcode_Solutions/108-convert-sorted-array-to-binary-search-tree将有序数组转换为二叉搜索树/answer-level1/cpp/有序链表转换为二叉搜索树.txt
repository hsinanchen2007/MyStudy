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
        int n = nums.size();
        return CreateBinaryTree(nums, 0, n-1);    
    }

    TreeNode* CreateBinaryTree(vector<int>& nums, int start, int end) {
        if(start > end) {
            return NULL;
        } else if (start == end) {
            TreeNode* res = new TreeNode(nums[start]);
            return res;
        }
        int mid = (start+end)/2;
        TreeNode* left = CreateBinaryTree(nums, start, mid-1);
        TreeNode* right = CreateBinaryTree(nums, mid+1, end);
        TreeNode* res = new TreeNode(nums[mid]);
        res->left = left;
        res->right = right;
        return res;
    }
};
```