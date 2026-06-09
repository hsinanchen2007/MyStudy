将树序列化（带空结点的或者前序+中序等序列化方法），Hash比较。
树哈希方法在本题中效率并不算高（MOD运算和stl的缘故），但这是一种能推广到更多问题的方法，希望能给大家带来帮助。
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
    const int BASE=20000623;
    const int MOD=998244353;
    unordered_map<int,bool> Mark;
    int dfs(TreeNode *x)
    {
        if (x==NULL) return 128979739;
        int v=dfs(x->left);
        v=1LL*v*BASE%MOD;
        v+=dfs(x->right);
        v%=MOD;
        v=1LL*v*BASE%MOD;
        v+=x->val;
        v%=MOD;
        Mark[v]=true;
        return v;
    }
    int dfs2(TreeNode *x)
    {
        if (x==NULL) return 128979739;
        int v=dfs2(x->left);
        v=1LL*v*BASE%MOD;
        v+=dfs2(x->right);
        v%=MOD;
        v=1LL*v*BASE%MOD;
        v+=x->val;
        v%=MOD;
        return v;
    }
public:
    bool checkSubTree(TreeNode* t1, TreeNode* t2) {
        dfs(t1);
        return Mark[dfs2(t2)];
    }
};
```
