新手迷思送给自己，也送给可能跟自己有相同想法的大家：对于这道题，其实是很容易想到使用递归。那么在自己画图的过程中，也就会想到比较左子树和右子树中较大的那个值，作为层数，这一切思路都是合理的。但是，我一开始做的时候，dfs的入参只有root，那么就会犯一个错误，函数的整个逻辑就变成了只要当前的节点不为空，那么就将maxDepth++；那么最后的结果就是，有几个点那么就加几次，这显然是错误的。那么，这里的解决方案就是，给下一个节点一个层数初值，将maxDepth作为参数代入，也就是给了其一个初值。函数值的问题自然也就解决了。网友的其他方法，pair的这种其实就是这种思想，每一个节点都有对应的层数，那么在遍历的时候，就不会无脑的++。
```
class Solution {
public:
    int dfs(TreeNode* root,int maxDepth){
        if(root==NULL) return maxDepth;
        maxDepth++;
        int leftnum=dfs(root->left,maxDepth);
        cout<<"leftnum="<<leftnum<<endl;
        int rightnum=dfs(root->right,maxDepth);
        cout<<"rightnum="<<rightnum<<endl;
        return max(leftnum,rightnum);
    }
    int maxDepth(TreeNode* root) {
        int maxDepth=0;
        return dfs(root,maxDepth);
    }
};
```
