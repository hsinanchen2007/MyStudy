### 解题思路
dfs搜索根节点到指定节点的路径并用栈存储，找最近公共祖先的思路与两链表找寻公共节点的思路一致，在二者size相等的情况下一一比较即可。

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
    bool search(TreeNode* root,stack<TreeNode*>& x,TreeNode* p){
        if(root==NULL)
            return false;
        x.push(root);
        if(root==p)
            return true;
        bool t=false;
        if(root->left!=NULL)
            t=search(root->left,x,p);
        if(!t&&root->right!=NULL)
            t=search(root->right,x,p);
        if(!t)
            x.pop();
        return t;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        stack<TreeNode*> x,y;
        bool a,b;
        a=search(root,x,p);
        b=search(root,y,q);
        while(x.size()>y.size())
            x.pop();
        while(y.size()>x.size())
            y.pop();
        while(!x.empty()&&!y.empty())
            if(x.top()==y.top())
                return x.top();
            else{
                x.pop();
                y.pop();
            }
        return NULL;
    }
};
```