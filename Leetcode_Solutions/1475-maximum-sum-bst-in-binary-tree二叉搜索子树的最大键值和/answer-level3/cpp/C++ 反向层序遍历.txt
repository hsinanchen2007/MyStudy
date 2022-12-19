## 代码

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    const int Boom = INT_MAX;
    int maxSumBST(TreeNode* root) {
        stack<TreeNode*> work;
        queue<TreeNode*> qt;
        if (root) {
            qt.push(root);
        }
        int ret = 0;
        map<TreeNode*, int> sum, min, max;
        while (!qt.empty()) { // 层序遍历二叉树，对叶子节点压栈
            auto cur = qt.front();
            qt.pop();
            sum[cur] = cur->val; // 记录每个子树的总值
            min[cur] = cur->val; // 记录每个子树的最小值
            max[cur] = cur->val; // 记录每个子树的最大值

            if (cur->left) {
                qt.push(cur->left);
            }
            if (cur->right) {
                qt.push(cur->right);
            }
            if (cur->left || cur->right)
                work.push(cur);
            else {
                if (cur->val > ret)
                    ret = cur->val;
            }
        }
        // 反向层序遍历
        while (!work.empty()) {
            auto w = work.top();
            work.pop();
            auto left = w->left;
            auto right = w->right;
            // 左右子树都是BST且 当前子树也是BST
            if ((!left || max[left] < w->val && sum[left] != Boom) &&
                (!right || min[right] > w->val && sum[right] != Boom)) { 
                if (left) { // 左子树存在时
                    sum[w] += sum[left];
                    min[w] = min[left];
                }
                if (right) { // 右子树存在时
                    sum[w] += sum[right];
                    max[w] = max[right];
                }

                if (sum[w] > ret) // 如果当前子树是BST 尝试更新返回值
                    ret = sum[w];
            } else
                sum[w] = Boom; // 当前子树不是BST 设置非法值标记
        }
        return ret;
    }
};
```