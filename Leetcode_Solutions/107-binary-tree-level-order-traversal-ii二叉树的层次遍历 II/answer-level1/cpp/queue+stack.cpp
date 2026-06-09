### 解题思路
1. 层级遍历二叉树,将每层节点放入stack
2. 遍历结束,弹出stack,放入vector
3. 返回vector

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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        stack<vector<int>> auxStack;
        queue<TreeNode*> levelQueue;
        if(root != NULL)
            levelQueue.push(root);

        vector<int> levelVector;
        while (!levelQueue.empty())
        {
            int len = levelQueue.size();
            levelVector.clear();
            for (int i = 0; i < len; ++i)
            {
                TreeNode * tmp = levelQueue.front();
                levelVector.push_back(tmp->val);
                levelQueue.pop();
                if (tmp->left != NULL)
                    levelQueue.push(tmp->left);
                if (tmp->right != NULL)
                    levelQueue.push(tmp->right);
            }
            auxStack.push(levelVector);
        }

        while (!auxStack.empty())
        {
            result.push_back(auxStack.top());
            auxStack.pop();
        }

        return result;
    }
};
```