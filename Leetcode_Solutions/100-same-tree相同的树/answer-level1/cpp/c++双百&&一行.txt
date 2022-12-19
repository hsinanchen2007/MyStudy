### 解题思路
![image.png](https://pic.leetcode-cn.com/f0e41bb0b55df93fc5d3fbe47e51497a5c579d5d0adac9a002209b3eca42b935-image.png)
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
        return (p!=NULL && q!=NULL)?p->val==q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right):p==NULL && q==NULL;
    }
};

```