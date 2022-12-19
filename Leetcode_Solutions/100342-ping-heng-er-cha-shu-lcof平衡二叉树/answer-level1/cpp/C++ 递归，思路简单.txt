### 解题思路
![image.png](https://pic.leetcode-cn.com/d35b32412842e8e340508f39bc8bd9a0cf03bd9a315a7eee0f937cd87d1cdecf-image.png)


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
    bool isBalanced(TreeNode* root) {
        if (root == NULL) {
            return true;
        }

        return isBalanced(root->left) 
                && isBalanced(root->right) 
                && abs(height(root->left) - height(root->right)) <= 1;
    }

    int height(TreeNode* node) {
        if (node == NULL) {
            return -1;
        }
        return std::max(height(node->left), height(node->right)) + 1;
    }
};
```
![码农黑板报.png](https://pic.leetcode-cn.com/6424e1c2dcd52a180a14f362d6134b68b400eaa1a855288a5d4e1a783a78b756-%E7%A0%81%E5%86%9C%E9%BB%91%E6%9D%BF%E6%8A%A5.png)
