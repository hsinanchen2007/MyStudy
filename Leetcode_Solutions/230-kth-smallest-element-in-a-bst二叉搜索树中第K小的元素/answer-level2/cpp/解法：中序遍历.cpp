### 解题思路
这道题的思路是很显然的，根据二叉搜索树的性质，通过中序遍历可以将一颗二叉搜索树转化成一个有序线性列表。

### 代码
```
/* 递归版本 */
class Solution {
    int x, n;
    void mt(TreeNode* t)
    {
        if(t && (n > 0))
        {
            mt(t->left);
            n--;
            if(!n) x = t->val;
            mt(t->right);
        }
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        n = k;
        mt(root);
        return x;
    }
};
```
```
/* 非递归版本：使用辅助栈 */
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> stk;
        TreeNode *t;
        for(t = root; t; t = t->left) stk.push(t);
        while(!stk.empty())
        {
            t = stk.top();
            k--;
            if(!k) return t->val;
            stk.pop();
            for(t = t->right; t; t = t->left) stk.push(t);
        }
        return 0; /* 在题设数据合法的情况下，这条语句永远不会被执行 */
    }
};
```