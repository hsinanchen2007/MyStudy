### 解题思路
在每一层的后面加一个NULL空指针，当遇到空指针说明次层结束，这时将此层的v放进res中，并清空v，pop出空指针，如果当前的queue为空则说明已经完成，退出即可，非空则说明还有下一层，此时要再push一个空指针进去，再次循环即可

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == NULL) return res;
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* temp = NULL;
        q.push(temp);
        vector<int> v;
        while (!q.empty()) {
            TreeNode* t = q.front();
            q.pop();
            if (t == NULL) {
                res.push_back(v);
                if (q.empty()) break;
                v.clear();
                q.push(temp);
            } else {
                v.push_back(t->val);
                if (t->left != NULL) q.push(t->left);
                if (t->right != NULL) q.push(t->right);
            }
        }
        return res;
    }
};
```