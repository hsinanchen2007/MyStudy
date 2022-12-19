### 解题思路
直观的看，需要用t去匹配s的每一个节点。可以采用先序遍历访问s的每个节点。在每次访问中匹配成功，则返回true。否则继续递归遍历s的左子树和右子树，并且返回其结果的并集。
递归的退出条件有两种情况：
1)上述匹配成功，返回true;
2)遍历完所有的节点，遇到叶节点的空指针，返回false。

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
    bool isSame(TreeNode* s, TreeNode* t){
        if(s==NULL&&t==NULL)
            return true;
        if(s!=NULL&&t!=NULL&&s->val == t->val)
            return isSame(s->left,t->left)&&isSame(s->right,t->right);
        else
            return false;
    }
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(s==NULL)
            return false;
        bool ans=false;
        TreeNode * p=s;
            if(t->val == p->val)
                ans = ans||(isSame(p->left,t->left)&&isSame(p->right,t->right));
            if(ans)
                return ans;
            else
                return isSubtree(p->left,t)||isSubtree(p->right,t);
            }
        
    
};
```