建议这题和最小深度，是否为平衡树一起练习
这里写了两种解法，时间复杂度一样，只不过一个是先到达叶子结点再计算，一个是边计算边往下走。
```
//置低向上
class Solution {
    
public:
    int maxDepth(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        return maxDepthHelper(root);
    }
    int maxDepthHelper(TreeNode *root)
    {
        if (root == NULL) {
            return 0;
        }
        int left = maxDepthHelper(root->left);
        
        int right = maxDepthHelper(root->right);
        
        return (left > right ? left : right) + 1;
    }
};

//置顶向下
//class Solution {
//    int max = 0;
//public:
//    int maxDepth(TreeNode *root)
//    {
//        if (root == NULL)
//        {
//            return 0;
//        }
//        maxDepthHelper(root, 1);
//        return max;
//    }
//    void maxDepthHelper(TreeNode *root,int depth)
//    {
//        if (root->left == NULL && root->right == NULL) {
//            max = max > depth ? max : depth;
//            return;
//        }
//        if (root->left != NULL) {
//            maxDepthHelper(root->left, depth + 1);
//        }
//        if (root->right != NULL) {
//            maxDepthHelper(root->right, depth + 1);
//        }
//    }
//};
```