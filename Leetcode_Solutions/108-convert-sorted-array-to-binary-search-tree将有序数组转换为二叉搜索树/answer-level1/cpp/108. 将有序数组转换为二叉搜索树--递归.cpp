### 解题思路
执行用时 :
28 ms
, 在所有 C++ 提交中击败了
24.75%
的用户
内存消耗 :
23.2 MB
, 在所有 C++ 提交中击败了
21.60%
的用户

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
    TreeNode* sortedArrayToBST(vector<int>& nums, int left, int right){
        if(left > right){
            return NULL;
        }
        int mid = (left + right) / 2;
        TreeNode *root = new TreeNode();
        root->val = nums[mid];
        root->left = sortedArrayToBST(nums, left, mid-1);
        root->right = sortedArrayToBST(nums, mid+1, right);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBST(nums, 0, nums.size()-1);
    }
};
```