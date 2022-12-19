### 解题思路
层序遍历  每遍历一层求一次平均值

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
        
        vector<double> v;

        if (root == nullptr)
            return v;

        queue<TreeNode*> q;
        q.push(root);

        TreeNode* last = root; //本层最后一个节点
        TreeNode* nlast = nullptr; //下一层最后一个节点

        double average = 0.0; //每层的平均数
        int count = 0; //每层的节点数

        while (!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();

            average += node->val;
            ++count;

            if (node->left)
            {
                q.push(node->left);
                nlast = node->left;
            }

            if (node->right)
            {
                q.push(node->right);
                nlast = node->right;
            }

            if (node == last) //本层最后一个节点出栈 进入下一层
            {
                last = nlast;

                average /= count;
                v.push_back(average);

                average = 0.0;
                count = 0;
            }
        }
        return v;
    }
};
```