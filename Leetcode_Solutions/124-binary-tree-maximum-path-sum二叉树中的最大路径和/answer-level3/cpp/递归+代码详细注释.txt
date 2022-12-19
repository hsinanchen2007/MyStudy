从叶子节点往上计算最大路径和

```c++
class Solution {
public:
    int _maxPathSum(TreeNode * root, int & max_sum)
    {
        if(!root)
            return 0;
        // 返回root左子树的最大路径和
        int l_sum = _maxPathSum(root->left, max_sum);
        // 返回root右子树的最大路径和
        int r_sum = _maxPathSum(root->right, max_sum);
        // 计算左子树+root的路径和
        int l_root_sum = l_sum + root->val;
        // 计算右子树+root的路劲和
        int r_root_sum = r_sum + root->val;
        // 计算经过root的最大路径和
        int sum = l_sum +  r_sum +  root->val;
        /* 对于以root为根的树，其最大路径和可能存在于以下面三种情况中:
        1. value(根) + path_sum(左子树) + path_sum(右子树) 
               a 
             /   \
            b     c
            即max_path_sum = a->val + path_sum(b) + path_sum(c)

        2. value(根) + path_sum(左子树)
               a 
             /   \
            b     c
            即max_path_sum = a->val + path_sum(b)
        3. value(根) + path_sum(右子树)
               a 
             /   \
            b     c
            即max_path_sum = a->val + path_sum(c)                   
        */
        // 求case1的最大路径和
        max_sum = max(sum, max_sum);
        // 求case2的最大路径和
        max_sum = max(max_sum, l_root_sum);
        // 求case3的最大路径和
        max_sum = max(max_sum, r_root_sum);
        /* 当前以root为根的树，还有可能是上层另一个节点的左子树或者右子树，为此需要返回
            当前树的单一路径的最大和，即l_roo_sum = root->val + path_sum(左子树) 和 
            r_root_sum = root->val + path_sum(右子树)的最大值
            当l_root_sum和r_root_sum 都小于0时，上层节点+max(l_root_sum, r_root_sum)只会更小，
            为此需要做截断，即小于0，则返回0
            考虑如下情况：
                                    9 
                                  /   \
                                 6     -3 
                                      /   \
                                     -6    2
                                         /  
                                        2
                                      /   \
                                    -6    -6
                                    /
                                  -6
            如果不加阈值判断，返回值为15。而正确值应该为16            
            */                       
        return max(l_root_sum, r_root_sum) < 0 ? 0 : max(l_root_sum, r_root_sum);
    }
    int maxPathSum(TreeNode* root) {
        if(!root)
            return 0;
        int max_sum = root->val;
        _maxPathSum(root, max_sum);
        return max_sum;
    }
};
```
