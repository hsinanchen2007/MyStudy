### 解题思路
利用两个栈，轮流交替存储每一层所有不为空的结点。

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
    vector<vector<int>> ans;
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL)
            return ans;
        vector<int> tmp;
        stack<TreeNode*> st0;
        stack<TreeNode*> st1;
        st0.push(root);
        int ceng=0;
        while(!st0.empty() || !st1.empty())
        {
            if(ceng%2==0)
            {
                int val=st0.top()->val;
                if(st0.top()->left!=NULL)
                    st1.push(st0.top()->left);
                if(st0.top()->right!=NULL)
                    st1.push(st0.top()->right);
                st0.pop();
                if(st0.empty())
                {
                    tmp.push_back(val);
                    ans.push_back(tmp);
                    vector<int>().swap(tmp);
                    ceng++;
                }
                else
                {
                    tmp.push_back(val);
                }
            }
            else
            {
                int val=st1.top()->val;
                if(st1.top()->right!=NULL)
                    st0.push(st1.top()->right);
                if(st1.top()->left!=NULL)
                    st0.push(st1.top()->left);
                st1.pop();
                if(st1.empty())
                {
                    tmp.push_back(val);
                    ans.push_back(tmp);
                    vector<int>().swap(tmp);
                    ceng++;
                }
                else
                {
                    tmp.push_back(val);
                }
            }
        }
        return ans;
    }
};
```