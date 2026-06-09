### 解题思路
使用递归的思想。

1.root为空，返回true；
2.root不为空，判断其左右子树是否互为反转树；
（1）左右子树互为反转树，返回true；
3.其他情况，返回false；

反转树函数
bool IsReverse(TreeNode* t1, TreeNode* t2)
1.t1,t2均为空，返回true；
2.除去情况1外，若t1或t2为空，返回false；
3.出去情况1、2外，即t1,t2均不为空，若t1->val == t2->val，继续判断：
（1）if(IsReverse(t1->left, t2->right) && IsReverse(t1->right, t2->left))，返回true；
其余情况，返回false；

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
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)
            return true;
        
        if(root != NULL)
        {
            if(IsReverse(root->left, root->right))
                return true;
        }
        return false;
    }

    bool IsReverse(TreeNode* t1, TreeNode* t2)
    {
        if(t1 == NULL && t2 == NULL)
            return true;
        if(t1 == NULL || t2 == NULL)
            return false;
        if(t1->val == t2->val)
        {
            if(IsReverse(t1->left, t2->right) && IsReverse(t1->right, t2->left))
                return true;
        }
        return false;
    }
};
```