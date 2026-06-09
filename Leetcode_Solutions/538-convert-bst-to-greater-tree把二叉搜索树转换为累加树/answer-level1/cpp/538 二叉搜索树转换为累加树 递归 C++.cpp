### 解题思路
其实就是后续遍历的变种题，
可以用递归和迭代，这里是递归
![image.png](https://pic.leetcode-cn.com/59685d7847a1ab76fc9eb24591ca7aa2db691d6e73f56ad001a6b0b71ffa7363-image.png)

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
    void convertBST(TreeNode* root, int & val) {
        if (!root) return;
        convertBST(root->right, val);
        root->val += val;
        val = root->val;
        convertBST(root->left, val);
    }
    TreeNode* convertBST(TreeNode* root) {
        if (!root) return NULL;
        int val = 0;
        convertBST(root, val);
        return root;
    }
};
```