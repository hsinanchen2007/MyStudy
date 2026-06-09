```c++
class Solution {
public:
    void calc_tree_sum(TreeNode * node, int sum, int cur_sum, int & sum_num)
    {
        if(!node)
            return ;
        cur_sum += node->val;
        if(cur_sum == sum)
        {
            sum_num++;
        }
        calc_tree_sum(node->left, sum, cur_sum, sum_num);
        calc_tree_sum(node->right, sum, cur_sum, sum_num);
    }
    void iterate_tree(TreeNode * node, int sum, int cur_sum, int & sum_num)
    {
        if(!node)
            return ;
        calc_tree_sum(node, sum, 0, sum_num);
        iterate_tree(node->left, sum, 0, sum_num);
        iterate_tree(node->right, sum, 0, sum_num);       
    }
    int pathSum(TreeNode* root, int sum) {
        int sum_num = 0;
        iterate_tree(root, sum, 0, sum_num);
        return sum_num;
    }
};
```
