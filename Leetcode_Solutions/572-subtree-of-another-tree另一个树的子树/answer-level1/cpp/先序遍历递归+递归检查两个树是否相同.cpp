```
class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(!s&&!t) return true;//如果s 和 t都为空 返回true
        if(!s) return false;//如果s为空了 t不为空 返回false
        return helper(s,t)||isSubtree(s->left,t)||isSubtree(s->right,t);//先根序遍历 判断s和t结构是否相同
    }

    bool helper(TreeNode* s,TreeNode* t)//判断s 和 t 是否结构相同
    {
        if(!s&&!t) return true;//如果s和t都为空 返回true
        if(!s||!t||s->val!=t->val) return false;//如果只有一个为空 或s的值不等于t的值 返回false
        return helper(s->left,t->left)&&helper(s->right,t->right);//然后递归检查这两个根节点的其他节点是否相同
    }   
};
```
