递归函数，设计方法可查看我之前559题《N叉树的最大深度》写的题解。
本题思路一致的，代码如下：
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
private:string s1,s2;//to_string()函数可以将int转换为string
public:
    void dfs(TreeNode* root,string &s){//注意传值方式要用引用，要么不传，否则全局变量被局部变量覆盖
        if(root==NULL) return;
        if(!root->left&&!root->right){s+=to_string(root->val);return;}
        dfs(root->left,s);
        dfs(root->right,s);
        return;
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        //string s1,s2;
        dfs(root1,s1);
        dfs(root2,s2);
        //cout<<"s1="<<s1<<endl<<"s2="<<s2<<endl;
        if(s1==s2) return true;
        return false;
    }
};
```
