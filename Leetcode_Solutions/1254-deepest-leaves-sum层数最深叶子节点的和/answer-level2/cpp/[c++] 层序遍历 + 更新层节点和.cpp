这道题考察基本层序遍历, 下面是迭代方法
```
class Solution {
public:
    int deepestLeavesSum(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        queue<TreeNode *> levelTraversal;
        levelTraversal.push(root);
        int sum = 0;
        while (!levelTraversal.empty()) {
            int size = levelTraversal.size();
            int tmpSum = 0;
            for (int i = 0; i < size; i++) {
                TreeNode *tmp = levelTraversal.front();
                levelTraversal.pop();
                tmpSum += tmp->val;
                if (tmp->left!= nullptr){
                    levelTraversal.push(tmp->left);
                }
                if (tmp->right!= nullptr){
                    levelTraversal.push(tmp->right);
                }
            }
            sum = tmpSum;
        }
        return sum;
    }
};
```
