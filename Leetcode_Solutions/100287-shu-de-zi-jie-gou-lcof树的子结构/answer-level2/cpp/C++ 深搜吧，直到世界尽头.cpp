### 解题思路
![image.png](https://pic.leetcode-cn.com/b3d7efd78b75a47b94a2543938818c95720e4decfe571229bc5e6c8ba2679125-image.png)


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
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if (A == NULL) {
            return false;
        }
        if (B == NULL) {
            return false;
        }
        return dfs(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }

    bool dfs(TreeNode* A, TreeNode* B) {
        if (B == NULL) {
            return true;
        }
        if (A == NULL) {
            return false;
        }
        if (A->val != B->val) {
            return false;
        }
        return dfs(A->left, B->left) && dfs(A->right, B->right);
    }
};
```
![码农黑板报.png](https://pic.leetcode-cn.com/2c2894cb5118cba5d41178b7eef76448742d7d57aad7e951be69a0caee7baece-%E7%A0%81%E5%86%9C%E9%BB%91%E6%9D%BF%E6%8A%A5.png)
