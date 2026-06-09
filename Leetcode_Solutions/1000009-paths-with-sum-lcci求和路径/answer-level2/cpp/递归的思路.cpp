在本题中，我们被要求可以不以根节点为出发点来求出所有路径值与sum相等的路径条数，
那么我们可以**首先假设**，如果这道题是必须从**根节点出发**来求出相应的路径和，代码如下：
下面这段代码只能求出从根节点出发的相应的路径和的条数。
从代码中我们可以看出，在pathsum函数中我是用根节点root来进行递归求出相应的路径和的，
那么问题就来了，为什么不可以把每个结点当成是根节点呢？这样不就符合题意了嘛？
怎么进行设计呢？根节点的左子树结点和右子树结点怎么当做根节点呢？

```
class Solution {
public:
    int res=0;
    int pathSum(TreeNode* root, int sum) {
        if(!root) return 0;
        
        dfs(root,sum,0);
        return res;
    }

    void dfs(TreeNode* root,int sum,int val)
    {
        if(!root) return ;
        val+=root->val;
        if(sum==val) res++;

        dfs(root->left,sum,val);
        dfs(root->right,sum,val);
    }
};
```
那么我们可以在pathsum函数中对左右子树进行递归，把root->left,root->right当做是根节点不就行了嘛？
故以下代码是正确代码：

```
class Solution {
public:
    int res=0;
    int pathSum(TreeNode* root, int sum) {
        if(!root) return 0;
        
        dfs(root,sum,0);
        if(root->left) pathSum(root->left,sum);
        if(root->right) pathSum(root->right,sum);
        return res;
    }

    void dfs(TreeNode* root,int sum,int val)
    {
        if(!root) return ;
        val+=root->val;
        if(sum==val) res++;

        dfs(root->left,sum,val);
        dfs(root->right,sum,val);
    }
};
```
若表达不清楚，还请在评论区指教