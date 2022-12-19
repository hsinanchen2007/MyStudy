### 解题思路
这个题没有什么好说的，二叉搜索树的性质~~

### 递归

```cpp
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root || root->val == val) return root;
        return root->val > val ? searchBST(root->left, val) : searchBST(root->right, val);
    }
};
```

### 迭代
```cpp
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        while(true){
            if(!root || root->val == val) return root;
            root = root->val > val ? root->left : root->right;
        }
    }
};
```