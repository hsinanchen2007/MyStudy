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
 #include<stack>
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root)return {};
        vector<vector<int>> res;
        stack<TreeNode *> A, B;  //两个栈
        int level = 0;
        A.push(root);  //初始化，root入栈A
        while(true)
        {
            if(A.empty() && B.empty())break;  //两个栈同时为空，退出
            vector<int> tempvec;
            if(level % 2 == 0)
            {
                while(!A.empty())
                {
                    //A全部出栈
                    TreeNode *temp = A.top();
                    tempvec.push_back(temp->val);
                    if(temp->left)B.push(temp->left);  //往B中先压左子树再压右子树
                    if(temp->right)B.push(temp->right);
                    A.pop();
                }
            }
            else
            {
                while(!B.empty())
                {
                    //B全部出栈
                    TreeNode *temp = B.top();
                    tempvec.push_back(temp->val);
                    if(temp->right)A.push(temp->right);  //往A中先压右子树再压左子树
                    if(temp->left)A.push(temp->left);
                    B.pop();
                }
            }
            res.push_back(tempvec);
            level += 1;
        }
        return res;
    }
};
```