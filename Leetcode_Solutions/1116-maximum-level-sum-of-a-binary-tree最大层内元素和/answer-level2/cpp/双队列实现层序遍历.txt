     核心思路：
     双队列实现程序遍历，
     队列 1 存放当前层节点，队列 2 存放下一层节点，
     当队列 1 为空时，该层遍历完毕，将该层节点之和 sum 与 max 比较，
     若 sum > max，则更新 ret 为当前所遍历的层数 level，
     随后将队列 2 中元素压入队列 1，
     返回 ret
```
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        if (!root) return 0;
        queue<TreeNode*> current_level, next_level;
        current_level.push(root);
        int max, sum, level, ret;
        sum = level = ret = 0;
        max = INT_MIN;
        while (!current_level.empty()) {
            TreeNode *node = current_level.front();
            current_level.pop();
            sum += node->val;
            if (node->left) next_level.push(node->left);
            if (node->right) next_level.push(node->right);
            if (current_level.empty()) {
                level += 1;
                if (max < sum) {
                    max = sum;
                    ret = level;
                }
                sum = 0;
                while (!next_level.empty()) {
                    current_level.push(next_level.front());
                    next_level.pop();
                }
            }
        }
        return ret;
    }
};
```
