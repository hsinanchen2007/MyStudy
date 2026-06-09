### 解题思路
利用max_element()函数找到指向最大值的迭代器，将原数组分为左右两边，递归。

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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return solve(nums.begin(),nums.end());
    }

    TreeNode* solve(vector<int>::iterator left, vector<int>::iterator right){
        if(left == right) return NULL;
        auto it = max_element(left,right);
        TreeNode* node = new TreeNode(*it);
        node->left = solve(left,it);
        node->right = solve(it+1,right);
        return node;
    }
};
```