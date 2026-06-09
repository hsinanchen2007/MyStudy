### 解题思路
取有序数组中间元素建立根结点，左侧元素递归建立左子树，右侧元素递归建立右子树

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
TreeNode* sortedArrayToBST(vector<int>& nums) 
{
    if (nums.size() == 0) return nullptr;
    int mid = (nums.size()-1) / 2;
    TreeNode* root = new TreeNode(nums[mid]);
    
    root->left = create_tree(nums, 0, mid - 1);
    root->right = create_tree(nums, mid + 1, nums.size()-1);
    return root;
}
TreeNode* create_tree(vector<int>& nums, int left, int right)
{
    if (right < left) return nullptr;
    int mid = (left + right) / 2;
    TreeNode* r = new TreeNode(nums[mid]);
    
    r->left = create_tree(nums, left, mid - 1);
    r->right = create_tree(nums, mid + 1, right);
    return r;
}
};
```