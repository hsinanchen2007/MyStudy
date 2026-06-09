### 解题思路
递归+回溯

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
    int sum = 0;
    void dfs(TreeNode *node, vector<int> &buff)
    {
        if (node == nullptr) {
            return;
        }

        buff.push_back(node->val);

        if (node->left == nullptr && node->right == nullptr) {
            stringstream sstream;
            int num = 0;
            for (auto n : buff) {
                sstream << n;
            }
            sstream >> num;
            sum += num;
        }


        dfs(node->left, buff);
        dfs(node->right, buff);

        buff.pop_back();
        return;
    }

    int sumNumbers(TreeNode *root)
    {
        sum = 0;
        vector<int> buff;
        dfs(root, buff);

        return sum;
    }
};
```