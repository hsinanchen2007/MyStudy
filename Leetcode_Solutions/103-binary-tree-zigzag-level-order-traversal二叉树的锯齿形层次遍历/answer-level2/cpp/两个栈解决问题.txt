### 解题思路
层次遍历是使用两个队列
锯齿形层次遍历是使用两个栈
注意：第二个栈在添加元素是需要从右至左添加元素

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        vector<int> temp_vec;
        if(root ==NULL)
        {
            return ret;
        }
        stack<TreeNode *> s1;
        stack<TreeNode *> s2;

        s1.push(root);
        TreeNode * temp;
        while(!s1.empty() || !s1.empty())
        {
            while(!s1.empty())
            {
                temp = s1.top();
                s1.pop();
                temp_vec.push_back(temp->val);
                
                if(temp->left != NULL)
                {
                    s2.push(temp->left);
                }
                if(temp->right != NULL)
                {
                    s2.push(temp->right);
                }
                
            }
            if(!temp_vec.empty())
            {
                ret.push_back(temp_vec);
            }
            temp_vec.clear();

            while(!s2.empty())
            {
                temp = s2.top();
                s2.pop();
                temp_vec.push_back(temp->val);
                
                if(temp->right != NULL)
                {
                    s1.push(temp->right);
                }
                if(temp->left != NULL)
                {
                    s1.push(temp->left);
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