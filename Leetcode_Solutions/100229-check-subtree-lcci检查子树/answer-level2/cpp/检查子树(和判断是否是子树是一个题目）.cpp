### 解题思路
这题我用的递归，上一个我用的是非递归，一样的解决思路。

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
    bool checkSubTree(TreeNode* t1, TreeNode* t2) {
        if(t2==NULL||t1==NULL) return false;
        return checkSubTree(t1->left,t2)||checkSubTree(t1->right,t2)||isSameTree(t1,t2);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL&&q==NULL) return true;
        if(p==NULL||q==NULL) return false;
        if(p->val!=q->val) return false;
        return isSameTree(p->right,q->right)&&isSameTree(p->left,q->left);
    }
};
```