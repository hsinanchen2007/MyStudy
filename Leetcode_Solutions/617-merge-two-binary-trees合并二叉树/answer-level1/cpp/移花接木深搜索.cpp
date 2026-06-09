### 解题思路
两个树同时进行深搜索，当我们之后要返回的树的其中一端为空时，直接移花接木。
挺简单

### 代码

```cpp
class Solution {
public:
    void dfs(TreeNode*t1,TreeNode*t2){
        if(!t2)return;

        if(t1&&t2)(*t1).val=t1->val+t2->val;
        if(t1->left)dfs(t1->left,t2->left);
        else(*t1).left=t2->left;//移花接木大法

        if(t1->right)dfs(t1->right,t2->right);
        else(*t1).right=t2->right;//移花接木大法

    }

    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(!t1)return t2;
        if(!t2)return t1;
        dfs(t1,t2);

        return t1;
    }
};
```