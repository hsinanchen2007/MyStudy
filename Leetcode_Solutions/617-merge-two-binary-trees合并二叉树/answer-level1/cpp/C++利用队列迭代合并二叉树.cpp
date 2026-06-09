### 解题思路

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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(t1 == NULL || t2 == NULL) {
            return t1 == NULL ? t2 : t1;
        }
        queue<TreeNode*> q;
        q.push(t1);
        q.push(t2);

        while(!q.empty()) {
            TreeNode *t1 = q.front();
            q.pop();
            TreeNode *t2 = q.front();
            q.pop();
            t1->val += t2->val;

            if(t1->left != NULL && t2->left != NULL) {
                q.push(t1->left);
                q.push(t2->left);
            } else if (t1->left == NULL) {
                t1->left = t2->left;
            }

            if(t1->right != NULL && t2->right != NULL) {
                q.push(t1->right);
                q.push(t2->right);
            } else if (t1->right == NULL) {
                t1->right = t2->right;
            }
        }
        return t1;
    }
};
```