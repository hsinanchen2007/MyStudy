### 解题思路
思路同101   ：核心关注这个递归函数本身是干什么的？当前问题需要用到子问题的解构建原问题的解 ，同时要把原问题划分更小的问题
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
    bool isSameTree(TreeNode* p, TreeNode* q)
    {
        if(p==NULL&&q==NULL)
            return true;
        if(p==NULL||q==NULL)
            return false;
        //两颗树的根节点值相同，还有保证两颗树的左子树，和右子树也相同
        return (p->val==q->val&&isSameTree(p->left,q->left)&&isSameTree(p->right,q->right));
        
    }
};
```