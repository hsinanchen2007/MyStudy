### 解题思路
这里采用queue进行迭代，每次塞入上一层的节点，
求出对应的size，然后循环获取其中的所有值；
一直迭代，直至queue empty。

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
        vector<vector<int>> result;
        queue<TreeNode*> queueNode;
        if (root == nullptr) {
            return result;
        }
        queueNode.push(root);
        while (!queueNode.empty()) {
            int queueSize = queueNode.size();
            vector<int> vecTmp;
            for (int i = 0; i<queueSize; i++) {
                TreeNode* tmpNode = queueNode.front();
                queueNode.pop();
                vecTmp.push_back(tmpNode->val);
                if (tmpNode->left != nullptr) {
                    queueNode.push(tmpNode->left);
                }
                if (tmpNode->right != nullptr) {
                    queueNode.push(tmpNode->right);
                }
            }
            result.push_back(vecTmp);
        }
        return result;
    }

};
```