### 思路
1. 中序遍历得到有序数组 [94. 二叉树的中序遍历](https://leetcode-cn.com/problems/binary-tree-inorder-traversal/)
2. 将有序数组转化为平衡二叉树 [108. 将有序数组转换为二叉搜索树](https://leetcode-cn.com/problems/convert-sorted-array-to-binary-search-tree/)

### 答题
```C++ []
TreeNode* sortedArrayToBSTHelper(vector<int>& nums, int start, int end) 
{
    if (start > end) return nullptr;

    TreeNode* root = nullptr;
    int mid = start + (end - start) / 2;
    root = new TreeNode(nums[mid]);
    root->left = sortedArrayToBSTHelper(nums, start, mid - 1);
    root->right = sortedArrayToBSTHelper(nums, mid + 1, end);
    return root;
}

void inorderTraversal(TreeNode* root, vector<int>& nums)
{
    if (root == nullptr) return;
    inorderTraversal(root->left, nums);
    nums.push_back(root->val);
    inorderTraversal(root->right, nums);
}

TreeNode* balanceBST(TreeNode* root)
{
    vector<int> nums;
    inorderTraversal(root, nums);
    TreeNode* node = sortedArrayToBSTHelper(nums, 0, nums.size() - 1);
    return node;
}
```



### 致谢

感谢您的观看，希望对您有帮助，欢迎热烈的交流！  

[我的leetcode](https://github.com/AhJo53589/leetcode-cn)


