### 解题思路
使用两个队列，一层一层交替使用
例如：
根节点push进第一个队列，然后遍历第一个队列，把其子节点push到第二个队列，知道第一个队列为空，跳出循环
然后开始遍历第二个队列，把相应的子节点push进第一个队列中

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
        vector<vector<int>> ret;
        vector<int> temp_vec;
        if(root ==NULL)
        {
            return ret;
        }
        queue<TreeNode *> q1;
        queue<TreeNode *> q2;

        q1.push(root);
        TreeNode * temp;
        while(!q1.empty() || ! q2.empty())
        {
            while(!q1.empty())
            {
                temp = q1.front();
                q1.pop();
                temp_vec.push_back(temp->val);
                if(temp->left != NULL)
                {
                    q2.push(temp->left);
                }
                if(temp->right != NULL)
                {
                    q2.push(temp->right);
                }
            }
            if(!temp_vec.empty())
            {
                ret.push_back(temp_vec);
            }
            temp_vec.clear();

            while(!q2.empty())
            {
                temp = q2.front();
                q2.pop();
                temp_vec.push_back(temp->val);
                if(temp->left != NULL)
                {
                    q1.push(temp->left);
                }
                if(temp->right != NULL)
                {
                    q1.push(temp->right);
                }
            }
            if(!temp_vec.empty())
            {
                ret.push_back(temp_vec);
            }
            
            temp_vec.clear();
            
        }
        return ret;

    }
};
```