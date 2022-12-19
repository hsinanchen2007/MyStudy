### 解题思路
借助队列，队列的元素是treeNode和对应的层次
while循环后，得到的res是层次遍历的结果，
最后需要把奇数层的结果倒置一下

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
    struct nodeLevel{
      TreeNode* node;
      int level;
    };
    int getDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int left = getDepth(root->left);
        int right = getDepth(root->right);
        return (left > right)? (left+1):(right+1);
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        // 层次遍历，
        int depth = getDepth(root);
        vector<vector<int>> res;
        res.resize(depth);
        if (root == NULL) {
            return res;
        }
        queue<nodeLevel> q;
        q.push({root, 0});
        while (!q.empty()) {
            // 取出元素
            nodeLevel node = q.front();
            TreeNode* treeNode = node.node;
            int currentLevel = node.level;

            res[currentLevel].push_back(treeNode->val);

            if (treeNode->left) {
                q.push({treeNode->left, currentLevel + 1});
            }
            if(treeNode->right) {
                q.push({treeNode->right, currentLevel + 1});
            }
            q.pop();
        }
        for (int i = 0; i < depth; ++i) {
            if(i % 2) {
                // 奇数层，需要倒置一下
                for (int j = 0, k = res[i].size()-1; j < k ; ++j, --k) {
                    int tmp = res[i][k];
                    res[i][k] = res[i][j];
                    res[i][j] = tmp;
                }
            }
        }
        return res;
    }
};
```