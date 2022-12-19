### 解题思路
此处撰写解题思路

### 代码
method1:迭代
![257_m1.jpg](https://pic.leetcode-cn.com/8405104876a9ad9ac3bf9dc7b851aba8a8adb036253b92b97d7522e991c808df-257_m1.jpg)
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
//method1:迭代法
#include <string>
#include <stack>
#include <utility>
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        stack<pair<TreeNode*, string>> loopStack;
        vector<string> resVec;
        TreeNode* curT = root;
        if(NULL == curT)
        {
            return resVec;
        }
        string curStr = to_string(root->val);
        while(curT != NULL)
        {
            if(!curT->left && !curT->right)
            {
                resVec.push_back(curStr);
                if(loopStack.empty())
                {
                    break;
                }
                else
                {
                    curT = loopStack.top().first->right;
                    curStr = loopStack.top().second +"->"+ to_string(curT->val);
                    loopStack.pop();
                }
            }
            else if(curT->left)
            {
                if(curT->right)
                {
                    loopStack.push(pair<TreeNode*,string>(curT,curStr));
                }
                curT = curT->left;
                curStr += "->" + to_string(curT->val);
            }
            else if(curT->right)
            {
                curT = curT->right;
                curStr += "->" + to_string(curT->val);                
            }
        }
        return resVec;
    }
};
```

method2:递归
![257_m2.jpg](https://pic.leetcode-cn.com/ee198b38ae759c5df3c42610ae59ab331a8bce940e5e5c60ab1acd19070d190f-257_m2.jpg)

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
//method2:递归

class Solution {
    vector<string> resVec;
public:
    void dfs(TreeNode* curT, string curStr)
    {
        if(!curT)
        {
            return;
        }
        if(!curT->left && !curT->right)
        {
            this->resVec.push_back(curStr);
        }
        if(curT->left)
        {
            dfs(curT->left, curStr+"->"+to_string(curT->left->val));
        }
        if(curT->right)
        {
            dfs(curT->right, curStr+"->"+to_string(curT->right->val));
        }
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        if(root)
        {
            dfs(root, to_string(root->val));
        }
        return this->resVec;
    }
};
```