### 解题思路
千万别看到平衡树就想着旋转
直接存节点比存值构造更方便

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
    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*> arr;
        dfs(root, arr);
        return construct(arr, 0, arr.size()-1);
    }

    void dfs(TreeNode* root, vector<TreeNode*>& arr) {
        if (!root) return;
        dfs(root->left, arr);
        arr.push_back(root);
        dfs(root->right, arr);
    }

    TreeNode* construct(vector<TreeNode*>& arr, int left ,int right) {
        if (left > right) return NULL;
        int mid = (left + right) / 2;
        arr[mid]->left = construct(arr, left, mid-1);
        arr[mid]->right = construct(arr, mid+1, right);
        return arr[mid];
    }
};
```