### 解题思路
![image.png](https://pic.leetcode-cn.com/6fd101cdec71db5d837ae583a9e013ed0954b539b4970cda2263909e9cc7b71d-image.png)


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
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) {
            return {};
        }
        return Dfs(1, n);
    }
    vector<TreeNode*> Dfs(int begin, int end) {
        if (begin > end) {
            return {nullptr};
        }
        vector<TreeNode*> result;
        for (int i = begin; i <= end; i++) {
            vector<TreeNode*> leftTree = Dfs(begin, i - 1);
            vector<TreeNode*> rightTree = Dfs(i + 1, end);
            for (auto left : leftTree) {
                for (auto right : rightTree) {
                    TreeNode* curNode = new TreeNode(i);
                    curNode->left = left;
                    curNode->right = right;
                    result.push_back(curNode);
                }
            }
        }
        return result;
    }
};
```