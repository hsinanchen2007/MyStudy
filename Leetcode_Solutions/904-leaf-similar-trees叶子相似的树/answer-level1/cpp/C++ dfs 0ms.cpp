![image.png](https://pic.leetcode-cn.com/d9afff280aee3eef650ccedcaf1644feb79a490eccfd1d66c9a5495344f6d4d3-image.png)

思路：
1.对于两棵树，都进行dfs
2.如果到达叶节点，放入当前节点到记录中，否则dfs左节点再dfs右节点
3.比较记录是否相等即可

```
class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> record1;
        vector<int> record2;
        dfs(record1, root1);
        dfs(record2, root2);
        return record1 == record2;
    }

private:
    void dfs(vector<int>& record, TreeNode* node) {
        if (node == nullptr) {
            return;
        }
        if (node->left == nullptr && node->right == nullptr) {
            record.emplace_back(node->val);
            return;
        }
        dfs(record, node->left);
        dfs(record, node->right);
    }
};
```

