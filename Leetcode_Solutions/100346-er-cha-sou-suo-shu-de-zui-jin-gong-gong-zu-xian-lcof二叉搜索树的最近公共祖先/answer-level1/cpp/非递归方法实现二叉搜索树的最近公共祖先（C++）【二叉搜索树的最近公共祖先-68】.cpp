### 解题思路
利用非递归的话，**其实就是顺着思维走，想清楚二叉搜索树以及两个节点公共祖先的思路。**
- 如果q,p的值均小于当前root的值，就去当前root的左子树查找，令root=root->left；（说明此时还不是最近的，两个节点还可以一起顺着走！）
- 如果q,p的值均大于当前root的值，就去当前root的右子树查找，令root=root->right;（说明此时还不是最近的，两个节点还可以一起顺着走！）
- 若都不满足，则p,q位于当前root的两侧，在此分道扬镳，所以当前root就是最近的公共祖先。

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL)  return NULL;
        TreeNode *t=root;
        while(t){
            if(p->val<t->val&&q->val<t->val){
            t=t->left;
        }
        else if(p->val>t->val&&q->val>t->val){
            t=t->right;
        }
        else{
            return t;
        }
        }
        return NULL;
    }
};
```