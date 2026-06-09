```C++ []
class Solution {
public:
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        TreeNode* dummy = new TreeNode(0);
        dummy->right = root;
        TreeNode* prev= dummy;
        TreeNode* curr = root;
        while (curr != NULL && curr->val > val) {
            prev = curr;
            curr = curr->right;
        }
        TreeNode* node = new TreeNode(val);
        node->left = curr;
        prev->right = node;
        return dummy->right;
    }
};
```

![image.png](https://pic.leetcode-cn.com/312f07935a22f98c55a7b9fcf33994ba4b82a6f9f2eecfc192d8af520ac3cfe3-image.png)
