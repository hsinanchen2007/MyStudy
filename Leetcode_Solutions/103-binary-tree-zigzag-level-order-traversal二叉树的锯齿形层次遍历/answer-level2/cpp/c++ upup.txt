### 解题思路
此处撰写解题思路
执行用时 :
0 ms
, 在所有 C++ 提交中击败了
100.00%
的用户
内存消耗 :
11.5 MB
, 在所有 C++ 提交中击败了
100.00%
的用户
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
        vector<vector<int>> ans;

        stack<TreeNode*> stk;
        if (root) stk.push(root);
        bool bFlag = true;
        while(!stk.empty())
        {
            vector<int> vec;
            stack<TreeNode*> tmp;
            while(!stk.empty())
            {
                TreeNode* tn = stk.top();
                vec.push_back(tn->val);
                stk.pop();
                if (bFlag)
                {
                    if (tn->left) tmp.push(tn->left);
                    if (tn->right) tmp.push(tn->right);
                }
                else
                {
                    if (tn->right) tmp.push(tn->right);
                    if (tn->left) tmp.push(tn->left);
                }
            }
            
            stk = tmp;
            bFlag = bFlag==true?false:true;
            ans.push_back(vec);
        }

        return ans;
    }
};
```