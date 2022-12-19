### 解题思路
有反向，觉得栈会比较方便，使用两个栈。（其实是看了题目提醒）
每两行为一循环，正反方向一次。
正向遍历时，按照先左节点后右节点，把每一个节点的子节点放入栈中；
反向遍历时，按照先右节点后左节点，把每一个节点的子节点放入栈中。

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
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> zig;
        stack<TreeNode *> stk1, stk2;
        if(root == NULL) return zig;
        stk1.push(root);
        while(!stk1.empty() || !stk2.empty())
        {
            vector<int> line;
            while(!stk1.empty()) //正向
            {
                TreeNode* cur= stk1.top();
                line.push_back(cur->val);
                stk1.pop();
                if (cur->left != NULL) stk2.push(cur->left);
                if (cur->right != NULL) stk2.push(cur->right);
            }
            if(line.size()) zig.push_back(line);
            line.clear();

             while(!stk2.empty()) //反向
            {
                TreeNode* cur= stk2.top();
                line.push_back(cur->val);
                stk2.pop();
                if (cur->right != NULL) stk1.push(cur->right);
                if (cur->left != NULL) stk1.push(cur->left);
            }
            if(line.size()) zig.push_back(line);
            line.clear();
        }
        return zig;
    }
};
```