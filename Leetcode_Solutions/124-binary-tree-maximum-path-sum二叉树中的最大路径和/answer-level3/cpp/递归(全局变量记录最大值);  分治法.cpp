```c++
class Solution {
public:
    // 官方递归的思路 我们首先要把握的点是 无论如何我们得到的这个路径一定以某个结点为根节点的, 换句话说, 对于每个根节点我们找以它向左和右延伸
        // 得到的最大值，这些最大值的最大值就是我们所求(也就是说我们这条路径是从左子树 到 根节点 到右子树的)。 为了方便地求以每个根节点向左，向右延伸得到的最大值，我们递归向上返回这个根节点向左路径或向右路径中的较大者(左子树到根节点 或 右子树到根节点)
        //官方教程说的很好 https://leetcode-cn.com/problems/binary-tree-maximum-path-sum/solution/er-cha-shu-de-zui-da-lu-jing-he-by-leetcode/

    int res=INT_MIN; //记录全局的最大值
    int maxPathSum(TreeNode* root) {
        recursion(root);
        return res;
    }

    int recursion(TreeNode* root){ //它的返回值 包括这个结点的一条最大的路径(或者通往左子树，或者通往右子树，或者只有根结点自己)
        if(root==NULL)
            return 0;
        else{
            int l=max(recursion(root->left), 0);   // 如果以左子树向下延伸的路径是负值，我们肯定不要，所以使用max取0和它的大者
            int r=max(recursion(root->right), 0);
            res=max(res,root->val+l+r); //尝试更新最大值
            return max(l,r)+root->val; //我们返回的值不是以它为根节点同时向左右延伸的； 而是包括这个结点的一条最大的路径(或者通往左子树，或者通往右子树，或者只有根结点自己)。
        }
    }

    // // 分治法 先计算左子树的二叉树最大路径和 ;再计算右子树的二叉最大路径和 ;  
    //     // 第三种就是一定要包含根节点的情况：要计算从左子树往下的延伸的最大路径和，从右子树往下延伸的最大路径和,
    //     // 之后考虑要不要把这两条路径分别加入到根节点的路径中。
    //     // 最后这上面这三者的最大值就是所求
    // int maxPathSum(TreeNode* root) {
    //     cache[NULL]=INT_MIN/2;
    //     recursion(root);
    //     return divide(root);
    // }

    // unordered_map<TreeNode*,int> cache; //来记录以某个结点向下延伸的最大路径和(一定包含这个结点)，但是可能不包含其他任何结点

    // int recursion(TreeNode *root){
    //     if(root == NULL) //空树 不是返回0 而是一个非常小的值
    //         return INT_MIN/2;
    //     else if(cache.count(root)!=0) //如果计算过了 直接返回
    //         return cache[root];
    //     else{ //没计算 就计算   要取左子树，右子树和0中大的那个 因为实在不成我可以不包括这些结点 只要根节点
    //         int Max=max(max(recursion(root->left),recursion(root->right)),0)+root->val;
    //         cache[root]=Max;
    //         return Max;
    //     }
        
    // }

    // int divide(TreeNode* root){
    //     if(root==NULL) //空树 返回一个极小的值  因为至少要有一个结点 要惩罚空树的情况
    //         return INT_MIN/3;
    //     else{
    //         int L=divide(root->left); //计算左子树
    //         int R=divide(root->right); //计算右子树
    //         int mid=root->val; //计算一定有根节点的情况
    //         mid=max(mid,mid+cache[root->left]); //只有左子树延伸的情况大于0才和左子树连接
    //         mid=max(mid,mid+cache[root->right]); //只有右子树延伸的情况大于0才和右子树连接
    //         return max(max(L,R),mid); //三者取大 
    //     }
    // }
    
    
};
```