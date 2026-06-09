isSelected表示当前节点（root）是否选用，递归结束的条件是root为nullptr。
memIsSelected和memIsNotSelected两个map用于储存每一个访问过的节点的计算结果。
之所以采用两个map来储存结果，是因为需要分储存的节点被选中以及不被选中两种情况。

```
class Solution {
public:
    int robCore(TreeNode* root, int isSelected, unordered_map<TreeNode*, int>& memIsSelected, unordered_map<TreeNode*, int>& memIsNotSelected)
    {
        int res = 0;
        if (isSelected && memIsSelected.find(root) != memIsSelected.end())
        {
            return memIsSelected[root];
        }
        else if (!isSelected && memIsNotSelected.find(root) != memIsNotSelected.end())
        {
            return memIsNotSelected[root];
        }

        if (root == nullptr)
        {
            res = 0;
        }
        else if (isSelected)
        {
            res = root->val + robCore(root->left, 0, memIsSelected, memIsNotSelected) + robCore(root->right, 0, memIsSelected, memIsNotSelected);
        }
        else
        {
            res = max(robCore(root->left, 1, memIsSelected, memIsNotSelected), robCore(root->left, 0, memIsSelected, memIsNotSelected)) + max(robCore(root->right, 1, memIsSelected, memIsNotSelected), robCore(root->right, 0, memIsSelected, memIsNotSelected));
        }

        if (isSelected)
        {
            memIsSelected[root] = res;
        }
        else
        {
            memIsNotSelected[root] = res;
        }

        return res;
    }

    int rob(TreeNode* root) {
        unordered_map<TreeNode*, int> memIsSelected, memIsNotSelected;
        return max(robCore(root, 0, memIsSelected, memIsNotSelected), robCore(root, 1, memIsSelected, memIsNotSelected));
    }
};
```


