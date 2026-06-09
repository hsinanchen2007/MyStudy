### 解题思路
比较自然的递归解法，思路参见注释

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
    bool dfs(TreeNode* p,TreeNode* q){
        if(p==NULL&&q==NULL)//如果两节点都为空
            return true;
        if(p==NULL||q==NULL)//如果两节点只有一个为空
            return false;
        if(p->val!=q->val)//如果两节点值不相等
            return false;
        bool temp=dfs(p->left,q->right);//先判断两侧
        if(temp==false)//两侧不对称，直接返回false
            return false;
        return dfs(p->right,q->left);//两侧对称，判断中间是否对称
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)//根节点为空
            return true;
        return dfs(root->left,root->right);
    }
};
```