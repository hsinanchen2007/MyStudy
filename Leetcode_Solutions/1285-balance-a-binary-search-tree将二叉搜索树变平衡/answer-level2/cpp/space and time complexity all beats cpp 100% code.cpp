### 解题思路
由于该题只要求对不平衡二叉搜索做平衡，不需要使用到左旋右旋，首先实现复杂，其次左旋右旋是当插入时候如何对不平衡的情况下保持平衡。
综合上述，需求仅仅是平衡，因此可以通过中序遍历将所有元素有序保存，然后通过中序建树操作，使其平衡
即build(0, mid - 1) + new TreeNode(nums[mid]) + build(mid + 1, nums.size() - 1)

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
        if (!root) return nullptr;
        vector<int> nums;
        
        function<void(TreeNode*)> inorder = [&](TreeNode* root) {
            if (!root) return;
            inorder(root->left);
            nums.push_back(root->val);
            inorder(root->right);
        };

        function<TreeNode*(int, int)> build = [&](int l, int r) {
            if (l > r) return (TreeNode*)nullptr; //匿名函数中返回值必须与TreeNode* 一致
            if (l == r) return new TreeNode(nums[l]);
            int mid = l + r >> 1;
            TreeNode* root = new TreeNode(nums[mid]);
            root->left = build(l, mid - 1);
            root->right = build(mid + 1, r);
            return root;
        };
        inorder(root);
        return build(0, nums.size() - 1);
    }
};
```