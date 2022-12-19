```
/*
 * Copyright (c) Nicolas-Tony Technologies Co., Ltd. 2019-2019. All rights reserved.
 * Description: i love leetcode
 * Author: Nicolas
 * Create: 2019/10/19
 */
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root)
    {
        if (root == NULL) {
            return vector<vector<int>>();
        }

        bool reverseOrder = false;

        vector<vector<int>> results;
        queue<TreeNode* > checkQueue;
        checkQueue.push(root);

        while (!checkQueue.empty()) {
            vector<int> levelData;
            zigzagLevelOrder(checkQueue, levelData);
            if (reverseOrder) {
                reverse(levelData.begin(), levelData.end());
            }
            results.push_back(levelData);
            reverseOrder = !reverseOrder;
        }
        return results;
    }

    void zigzagLevelOrder(queue<TreeNode *> &checkQueue, vector<int> &levelData)
    {
        int size = checkQueue.size();
        while (size > 0) {
            TreeNode* current = checkQueue.front();
            checkQueue.pop();
            levelData.push_back(current->val);
            if (current->left != NULL) {
                checkQueue.push(current->left);
            }
            if (current->right != NULL) {
                checkQueue.push(current->right);
            }
            size--;
        }
    }
};
```
