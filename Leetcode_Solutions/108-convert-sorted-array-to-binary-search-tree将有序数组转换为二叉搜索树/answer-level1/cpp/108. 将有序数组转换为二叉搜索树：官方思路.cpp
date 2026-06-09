### 解题思路
* 官方思路

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
        if(nums.empty())    return NULL;
        return inorder(nums, 0, nums.size()-1);
    }
    TreeNode* inorder(vector<int>& nums, int left, int right) {
        if(left > right)    return NULL;
        
        int p = (left + right) / 2;

        TreeNode *root = new TreeNode(nums[p]);
        root->left = inorder(nums, left, p-1);
        root->right = inorder(nums, p+1, right);

        return root;
    }
};
```
![4.png](https://pic.leetcode-cn.com/98861a3006c7c9eca231d23fe9d7c94440df382eb1986dc510a23aa4e9f1c6bb-4.png)


