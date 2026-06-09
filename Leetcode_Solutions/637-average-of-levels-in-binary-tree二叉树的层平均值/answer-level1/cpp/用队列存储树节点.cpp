### 解题思路
用队列存储树节点

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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> averVec;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty())
        {
            double sum = 0;
            int size = que.size();
            int i = 0;
            while(i<size)
            {
                TreeNode* front = que.front();
                que.pop();
                sum += front->val;
                root = front;
                if(root->left)
                    que.push(root->left);
                if(root->right)
                    que.push(root->right);
                i++;
            }
            double average = sum/(double)i;
            averVec.push_back(average);
        }
        return averVec;
    }
};
```