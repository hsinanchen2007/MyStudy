### 解题思路
1、优先判断边界是否满足。
2、其次判断当左右子树的val相等的情况下，左右子树的左右分支是否相等。

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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL){
            return true;
        }
        if(p == NULL || q == NULL){
            return false;
        }
        if(p->val == q->val){
            return isSameTree(p->left, q->left)&&isSameTree(p->right, q->right);
        }
        return false;
    }
};
```