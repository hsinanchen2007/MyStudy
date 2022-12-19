**思路见代码**
```
class Solution {
public:
    int maxN = 0; // 最大结果
    unordered_map<TreeNode *, int> mem; // 记忆数组,防止DFS二次遍历

    int maxSumBST(TreeNode *root) {
        /**
         * 遍历所有树节点,每个节点执行查找最大值操作
         */
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode *t = q.front();
            q.pop();
            maxSum(t);
            if (t->left != nullptr) q.push(t->left);
            if (t->right != nullptr) q.push(t->right);
        }
        return maxN;
    }

    int maxSum(TreeNode *root) {
        /**
         * 已遍历过 直接返回
         */
        if (mem.find(root) != mem.end()) {
            return mem[root];
        }
        /**
         * 空节点或叶子节点直接判断返回:
         * 空节点 -> 返回和为0
         * 叶子节点 -> 返回叶子节点值
         */
        if (root == nullptr || (root->left == nullptr && root->right == nullptr)) {
            if (root != nullptr) {
                maxN = max(maxN, root->val);
                mem[root] = root->val;
                return root->val;
            }
            return 0;
        }

        /**
         * 由于题目设置了负数,并且防止误判断,所有左右空节点值假设为合理节点
         */
        int l = root->left == nullptr ? -4000000 : root->left->val;
        int r = root->right == nullptr ? 4000000 : root->right->val;

        if (l < root->val && root->val < r ) {
            /**
             * DFS遍历左右节点
             */
            int ll = maxSum(root->left);
            int rr = maxSum(root->right);
            /**
             * 左右节点合理,返回总和
             */
            if (ll != -4000000 && rr != -4000000) {
                maxN = max(maxN, root->val + ll + rr);
                mem[root] = root->val + ll + rr;
                return root->val + ll + rr;
            }
        }
        /**
         * 该节点不符合二分搜索树性质 以下所有子树均不合格 返回不合理值
         */
        return -4000000;
    }
};
```
