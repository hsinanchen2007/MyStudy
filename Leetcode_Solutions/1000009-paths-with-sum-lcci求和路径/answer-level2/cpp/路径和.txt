见代码注释

```
class Solution {
   public:
    int pathSum(TreeNode* root, int sum) {
        path(root, sum, 0);
        return res;
    }

   private:
    void path(TreeNode* root, int sum, int pSum) {
        if (!root) return;

        // 当前节点加入路径中
        p.push_back(root->val);
        // 更新路径和
        pSum += root->val;

        int t = pSum;
        // 比较到当前节点为止的路径和
        if (t == sum) res++;
        // 从根节点开始移除，判断剩下的路径和是否为 sum
        for (int i = 0; i < p.size() - 1; i++) {
            t -= p[i];
            if (t == sum) res++;
        }

        // 递归判断左子树
        if (root->left) {
            path(root->left, sum, pSum);
            p.pop_back();
        }

        // 递归判断右子树
        if (root->right) {
            path(root->right, sum, pSum);
            p.pop_back();
        }
    }

    vector<int> p;
    int res = 0;
};
```
