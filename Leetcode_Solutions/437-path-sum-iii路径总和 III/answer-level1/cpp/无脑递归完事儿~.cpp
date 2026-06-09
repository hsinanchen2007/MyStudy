左边节点路径和数量（pathSum(root->left,sum)），右边节点路径和数量（pathSum(root->right,sum)），以及当前节点开始的连续路径和数量(pathSumHelper(root,sum)）。
对于当前节点开始的连续路径和数量（pathSumHelper)又可以递归为左边节点连续路径和数量与右边节点连续路径和数量，**如果当前节点与sum相等，就让返回值再加1**.
代码
```
class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        if(root == nullptr) return 0;
        if(root->left == nullptr && root->right == nullptr){
            if(root->val == sum) return 1;
            else return 0;
        }    
        int leftPathSum = pathSum(root->left,sum) ;
        int rightPathSum = pathSum(root->right,sum);
        return leftPathSum + rightPathSum + pathSumHelper(root,sum);
    }
    int pathSumHelper(TreeNode* root, int sum)
    {
        if(root == nullptr) return 0;
        if(root->left == nullptr && root->right == nullptr){
            if(root->val == sum) return 1;
            else return 0;
        }
        int cur = 0;
        if(root->val == sum) cur = 1;
        int remain = sum - root->val;
        int leftPath = pathSumHelper(root->left,remain);
        int rightPath = pathSumHelper(root->right,remain);
        return cur + leftPath+rightPath;
    }
};
```
