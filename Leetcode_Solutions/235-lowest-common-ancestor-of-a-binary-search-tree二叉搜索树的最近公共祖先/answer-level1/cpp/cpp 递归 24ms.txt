![image.png](https://pic.leetcode-cn.com/4a81292f6cfbb9d3bdddf19db6541c18298865b227df5aa0c3eb6a17f4922ef7-image.png)

思路：
1.p和q都比当前节点大，说明p和q都在右子树，递归右节点
1.p和q都比当前节点小，说明p和q都在左子树，递归左节点
3.否则p和q一个在左子树，一个在右子数，返回当前节点

```
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root->val < p->val && root->val < q->val) {
            return lowestCommonAncestor(root->right, p, q);
        }
        if (root->val > p->val && root->val > q->val) {
            return lowestCommonAncestor(root->left, p, q);
        }
        return root;
    }
};
```
