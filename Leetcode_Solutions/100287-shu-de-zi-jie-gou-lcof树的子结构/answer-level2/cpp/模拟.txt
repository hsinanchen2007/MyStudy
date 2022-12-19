### 解题思路
从***刷剑指过来的，因为***剑指题库不能输出自定义的输出，完全没法调代码。
这题大佬说法是转换成字符串再KMP，我这样的菜鸡就直接模拟了。
主要函数两部分，一两树对比，我文中的dfs函数，注意的就是只要判子树节点为空就行了，第二部分就是遍历，什么遍历都可以，我用了先序；
代码还是比较简洁的，哈哈。

### 代码

```
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
    bool   dfs (TreeNode* p,TreeNode* q)
 {
     if(q==NULL) return true;
     if(p!=NULL&& q!=NULL&& p->val==q->val)  return dfs(p->left,q->left) & dfs(p->right,q->right);
     else return false;
 }
 void inorder(TreeNode* pRoot1, TreeNode* pRoot2,vector<bool> &res)
 {
     if(pRoot1==NULL) return;
          res.push_back(dfs( pRoot1, pRoot2));
          inorder(pRoot1->left,pRoot2,res);
          inorder(pRoot1->right,pRoot2,res);
 }
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(A==NULL || B==NULL) return false;
        vector<bool> res;
       inorder(A,B,res);
        bool tag=false;
     for(auto i:res) tag=i|tag;
        return tag;
    }
};
```