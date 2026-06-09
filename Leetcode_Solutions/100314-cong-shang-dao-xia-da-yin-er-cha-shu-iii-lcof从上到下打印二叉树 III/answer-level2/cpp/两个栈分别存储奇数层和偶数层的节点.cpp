### 解题思路
两个栈stack1和stack2分别存放奇数层和偶数层的节点。
清空stack1过程中，依次将栈顶节点子节点（先左后右）压入stack2
清空stack2过程中，依次将栈顶节点子节点（先右后左）压入stack1
直到stack1和stack2都为空。

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
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        int level=1;
        stack<TreeNode*> stack1;  //存放奇数层节点
        stack<TreeNode*> stack2;  //存放偶数层节点
        stack1.push(root);

        while(!stack1.empty() || !stack2.empty())
        {
            vector<int> tmp;
            if(level & 1)
            {
                while(!stack1.empty())      //清空stack1时，依次将栈顶节点子节点（先左后右）压入stack2
                {
                    TreeNode* top = stack1.top();
                    tmp.push_back(top->val);
                    stack1.pop();
                    if(top->left) stack2.push(top->left);      
                    if(top->right) stack2.push(top->right);
                }
            }
            else
            {
                while(!stack2.empty())       //清空stack2时，依次将栈顶节点子节点（先右后左）压入stack1
                {
                    TreeNode* top = stack2.top();
                    tmp.push_back(top->val);
                    stack2.pop();
                    if(top->right) stack1.push(top->right);
                    if(top->left) stack1.push(top->left);
                }
            }
            ans.push_back(tmp);
            level++;
        }
        return ans;

    }
};
```