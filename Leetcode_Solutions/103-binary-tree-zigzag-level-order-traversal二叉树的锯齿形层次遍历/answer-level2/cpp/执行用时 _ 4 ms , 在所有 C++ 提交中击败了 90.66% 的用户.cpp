### 解题思路
此处撰写解题思路

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        vector<vector<int>>res;
        if(root == nullptr)
        {
            return res;
        }
        stack<TreeNode*>levels[2];
        int current = 0;
        int next = 1;
        levels[current].push(root);
        vector<int>temp;
        while(!levels[0].empty()||!levels[1].empty())
        {

            TreeNode * Node = levels[current].top();
            levels[current].pop();
            temp.push_back(Node->val);
            if(current == 0)
            {
                if(Node->left != nullptr)
                {
                    levels[next].push(Node->left);
                }
                if(Node->right != nullptr)
                {
                    levels[next].push(Node->right);
                }
            }
            else
            {
                if(Node->right != nullptr)
                {
                    levels[next].push(Node->right);
                }
                if(Node->left != nullptr)
                {
                    levels[next].push(Node->left);
                }
            }
            if(levels[current].empty())
            {
                res.push_back(temp);
                temp.clear();
                current = 1-current;
                next = 1-next;
            }
        }
        return res;
    }
};
```