首先理解好题目的意思:从任意的节点到任意节点，是用线穿起来的
思路：
1.把每一个节点看作最大路径和，计算根加左加右的"正值"
2.每个结点返回的是：根以下最大路径(一条线)(左子树或右子树)
递归的方法和求DFS差不多，都是根左右
```
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int Max = -9999;
        Sum(root, Max);
        return Max;
    }
    int Sum(TreeNode *root,int &Max){
        int LeftMax=0,RightMax=0;

        int NowMax = root->val;
        int re = root->val;

        if(root->left != nullptr) LeftMax = Sum(root->left, Max);
        if(root->right != nullptr) RightMax = Sum(root->right, Max);

        //判断以当前结点为根,是不是最大值
        if(LeftMax > 0) NowMax += LeftMax;
        if(RightMax > 0) NowMax += RightMax;
        if(NowMax > Max) Max = NowMax;

        //确认返回值
        int tmp = (LeftMax > RightMax ? LeftMax : RightMax);
        if(tmp > 0) re += tmp;

        return re;
    }
};
```
