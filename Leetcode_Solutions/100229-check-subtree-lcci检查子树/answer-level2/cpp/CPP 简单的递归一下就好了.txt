### 解题思路
1. 看描述，以为会有效率问题，就先随便写了一下。结果直接通过了
2. 题目本身比较简单，在某个节点检查下是否相同，不同的话，检查左子树或者右子树是否相同。

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
    bool checkSameTree(TreeNode* t1, TreeNode* t2) {
        if (t1 == NULL || t2 == NULL) {
            return t1 == t2;
        }

        if (t1->val != t2->val) {
            return false;
        }
        return checkSameTree(t1->left, t2->left) && checkSameTree(t1->right, t2->right);
    }

    bool checkSubTree(TreeNode* t1, TreeNode* t2) {
        if (t1 == t2) {
            return true;
        } else if (t1 == NULL) {
            return false;
        }
        if (checkSameTree(t1, t2)) {
            return true;
        }
        return checkSubTree(t1->left, t2) || checkSubTree(t1->right, t2);
    }
};
```