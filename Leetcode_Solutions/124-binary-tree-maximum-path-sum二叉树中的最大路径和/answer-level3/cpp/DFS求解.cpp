由于起始终止节点位置是任意的。所以我们可以先假设起始点拥有左右子节点。
则以当前节点为**根节点**会出现四种情况。

1. 最大路径为左子树加上根节点的值
2. 最大路径为右子树加上根节点的值
3. 最大路径为左右子树和加上根节点的值
4. 最大路径为根节点自身的值
这四种情况是**默认当前节点为根节点**时的情况，但是当仍有父节点时，上述的第三种情况不成立，于是要做的是。
1. 确定当前节点下的最大路径值
2. 确定如果有父节点时的最大路径值

可以想到将结果值作为全局变量，每次递归调用得到的当前节点的最大路径和与之比较求最大值，而有父节点的最大路径值作为递归的返回值（也就是选择最大值的路径）即可。
```
class Solution {
public:
    int res;
    int maxPathSum(TreeNode* root) {
        res = INT_MIN;
        maxDFSsum(root);
        return res;
    }

    int maxDFSsum(TreeNode* root){
        if(root == NULL) return 0;
        int leftpath = max(0,maxDFSsum(root->left));
        int rightpath = max(0,maxDFSsum(root->right));
        int cursum = root->val + leftpath + rightpath;
        res = max(res,cursum);
        return (root->val + max(leftpath,rightpath));
    }
};
```
