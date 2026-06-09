思路：
/对于任何一个节点，以他为顶点的的最长路径（有可能是全局最长的）包括四种情况：
1.上凸型，也即是此节点与左右节点都相同。那么以他为顶点的最长路径=左子节点最长路径+右子节点最长路径+2
2.左型，即这条路径只经过它和它的左节点，右节点为0.那么以他为顶点的最长路径=左子节点最长路径+1
3.右型，与2相似，这条路径只经过它和它的右节点，左节点为0；那么以他为顶点的最长路径=右子节点最长路径+1
4.没有子节点与其相连或者相同。那么最长路径就应该为0；
由上述分析可以看出，我们每求一个父节点的最长路径，就需要用相同的方法来求其子节点的最长路径
很明显，这是一个递归问题。而终止条件即为没有子节点与其相连或者相同。最后输出应该为在所有节点中以其为顶点的最长的那条路径的长度。
class Solution {
private:int maxL=0;int a=1;//必须加：
public:
    int longestUnivaluePath(TreeNode* root) {
        if(root==NULL) {return 0;}//NULL必须全大写
        getMaxL(root);//结构体引用不能用.
        return maxL;
    }
private:
        int getMaxL(TreeNode* root)
    {
        if(root==NULL) return 0;
        int left=getMaxL(root->left);//必须加int 来定义数据类型
        int right=getMaxL(root->right);
        if(root->left==NULL||root->right==NULL)a=1;else if (root->val==root->left->val&&root->val==root->right->val){maxL=max(maxL,left+right+2);return max(left,right)+1;}//如果此顶点的最长路径更大，更新maxL;注意的是，当root的两个子节点为空时，调用root->right_>val或者。。会出错，所以要先判断
        if(root->left==NULL)a=1;else if(root->val==root->left->val){maxL=max(maxL,left+1);return left+1;}
        if(root->right==NULL)a=1;else if(root->val==root->right->val) {maxL=max(maxL,right+1);return right+1;}   
        return 0;
    }
};
