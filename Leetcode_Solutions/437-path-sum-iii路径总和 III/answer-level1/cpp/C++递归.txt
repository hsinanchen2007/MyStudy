```
class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        return dfs(root,sum,1);
    }
    int dfs(TreeNode* root,int sum,int flag){
        if(!root)return 0;
        if(flag)return dfs(root->left,sum,flag)+dfs(root->right,sum,flag)+dfs(root->left,sum-root->val,flag-1)+dfs(root->right,sum-root->val,flag-1)+(sum==root->val);
        else return dfs(root->left,sum-root->val,flag)+dfs(root->right,sum-root->val,flag)+(sum==root->val);
    }
};
```
一个简单的递归解决方案，按其中一个节点为例子，倘若这个节点不是路径最终的那个节点，往下寻找时，有两种方案：1，路径中包含当前节点，那么接下来的子树根节点必须也被包含，否则会产生断裂，这个flag就是一个判断子树根节点需不需要被包含的用作；2.路径中的点不需要被包含，那么一切和原先一样