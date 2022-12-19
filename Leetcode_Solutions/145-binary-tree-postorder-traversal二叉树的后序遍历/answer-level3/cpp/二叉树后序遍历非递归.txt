### 解题思路
此处撰写解题思路 
为什么23、29行一定要加p!=NULL 才能通过
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> des;
        stack<TreeNode*> stk1;
        stack<TreeNode*>stk2;
        TreeNode* p=root;
        stk1.push(root);
        while(!stk1.empty())
        {
            p=stk1.top();
            stk1.pop();
            stk2.push(p);
            if(p!=NULL&&p->left !=NULL) stk1.push(p->left);
            if(p!=NULL&&p->right!=NULL) stk1.push(p->right);
        }
        while(!stk2.empty())
        {
            p=stk2.top();
            if(p!=NULL)des.push_back(p->val);
            stk2.pop();
        }
    return des;
    }
};
```