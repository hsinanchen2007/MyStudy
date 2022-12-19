递归，找到左右子树的最大值和0比较，大于0就加上当前节点值，不是就直接返回当前节点值。然后给一个成员变量一直比较可能出现的最大值，注意左右子树只要大于0可累加。
```
class Solution {
public:
    int res=INT_MIN;
    int currentmax(TreeNode* node){
        if(node==NULL)
            return 0;
        int max1=currentmax(node->left);
        int max2=currentmax(node->right);
        int tmp=node->val;
        if(max1>0)
            tmp=tmp+max1;
        if(max2>0)
            tmp=tmp+max2;
        res=max(tmp,res);
        return max(max(max1,max2),0)+node->val;
    }
    int maxPathSum(TreeNode* root) {
        currentmax(root);
        return res;
    }
};
```

