### 解题思路
使用双重的递归解决。
第一个递归是在A里面找到和B的根节点相同的节点，第二个递归是找到之后，开始遍历是不是和B相同的子树结构。
这题目留意两个递归的对B是否非空判断条件并不相同。

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
    bool do_isSubStructure(TreeNode* A, TreeNode* B) {
        if (B == NULL) {
            return true;
        }
        if (A == NULL) {
            return false;
        }
        if (A->val == B->val) {
            return do_isSubStructure(A->left, B->left) && do_isSubStructure(A->right, B->right);
        }
        return false;
    }

    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if (B == NULL) {
            return false;
        }
        if (A == NULL) {
            return false;
        }
        return do_isSubStructure(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }
};
```