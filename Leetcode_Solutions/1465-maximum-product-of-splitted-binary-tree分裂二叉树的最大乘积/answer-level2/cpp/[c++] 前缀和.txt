**原地修改所有节点值,每个节点值保存该节点值与左右子树和,所以 其他节点和 = sum - 左子树和**
**分裂两种情况,该点左侧断裂 left = 左子树和 * 其他节点和,右侧同理**

```
using ll=long long;
class Solution {
public:
    ll res = 0;

    int maxProduct(TreeNode *root) {
        changeValue(root);
        int sum = root->val; // 第一个节点就是所有节点和
        findMax(root,sum);
        res %= 1000000007;
        return res;
    }

    void findMax(TreeNode *root, int sum) {
        if (root == nullptr) return;
        ll l = 0, r = 0;
        /**
         * 分裂两种情况,该点左侧断裂 l = 左子树和 * 其他节点和 
         * 由于每个节点存储该节点和左右子树和,所以 其他节点和 = sum - 左子树和,右侧同理
         */
        if (root->left != nullptr) l = (ll)root->left->val * (ll)(sum - root->left->val);
        if (root->right != nullptr) r = (ll)root->right->val * (ll)(sum - root->right->val);
        res = max(l, max(r, res));
        findMax(root->left, sum); // 递归
        findMax(root->right, sum);
    }

    /**
     * 生成前缀树,每个节点保存该节点和左右子树和
     */
    int changeValue(TreeNode *root) {
        if (root == 0) return 0;
        root->val = changeValue(root->left) + changeValue(root->right) + root->val;
        return root->val;
    }
};
```
