### 解题思路
与前中后颜色标记法一样，加了一个level而已。

[前中后遍历题解](https://leetcode-cn.com/problems/binary-tree-level-order-traversal/solution/c-yi-ge-fang-fa-jie-jue-er-cha-shu-zheng-xu-ni-xu-/)

### 代码

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

 struct Property {
     int color;
     TreeNode* node;
     int level;
     Property(int c, TreeNode* n, int l) : color(c), node(n), level(l) {}
 };
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        //F(root);
        vector<vector<int>> res;
        stack<Property> s;
        int white = 1;
        int grey = 0;
        int level = 0;
        s.push(Property(white, root, level));

        int count = 0;
        while(!s.empty()) {
            int color = s.top().color;
            int level = s.top().level;
            TreeNode* node = s.top().node;
            s.pop();
            if(node == NULL) continue;
            if(color == white) {
                s.push(Property(white, node->right, level+1));
                s.push(Property(white, node->left, level+1));
                s.push(Property(grey, node, level));
            }
            else {
                if(level == res.size()) res.push_back({});//关键，不然会溢出，当level和res高度一样的时候，添加一个新行
                res[level].push_back(node->val);
            }
        }

        return res;
    }
};
```