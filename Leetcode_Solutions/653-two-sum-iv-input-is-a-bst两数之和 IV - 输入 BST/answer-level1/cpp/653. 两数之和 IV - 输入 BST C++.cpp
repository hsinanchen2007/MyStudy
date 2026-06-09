### 解题思路
先中序遍历，将元素存入数组，再使用两数之和II的双指针方法找两个数

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

    void inorder_traversal(TreeNode* node, vector<int>& nums)
    {
        if (node == nullptr)
            return;

        inorder_traversal(node->left, nums);
        nums.push_back(node->val);
        inorder_traversal(node->right, nums);
    }


    bool findTarget(TreeNode* root, int k) {

        vector<int> nums;
        inorder_traversal(root, nums);

        int left = 0;
        int right = nums.size() - 1;

        while (left < right)
        {
            int sum = nums.at(left) + nums.at(right);
            if (sum == k)
            {
                return true;
            }
            else if (sum > k)
            {
                --right;
            }
            else
            {
                ++left;
            }
        }

        return false;
    }
};
```