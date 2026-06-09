### 解题思路
先序遍历

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
        if (t1 == NULL)
        {
             //两树的值比较，以一个为基准
            return t2;
        }
        if (t2 == NULL) 
        {
            return t1;
        }

        t1->val += t2->val;//合并当前节点相应的值值，主要操作
        t1->left = mergeTrees(t1->left, t2->left);//下层调用
        t1->right = mergeTrees(t1->right,t2->right);
        return t1;//
    }
};
```