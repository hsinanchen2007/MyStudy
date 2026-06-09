### 解题思路
使用两个栈来保存已经遍历过的节点和对应节点的状态
1、状态为0，则说明右子树还未访问过，因此将当前节点推回栈中，并且遍历当前节点的右子树，并且标志1推到栈中；
2、状态为1，说明右子树已经访问过了，因此可以直接输出该节点了

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
        stack<int> st1;
        stack<TreeNode*> st2;
        vector<int> res;
    vector<int> postorderTraversal(TreeNode* root) {
        if(root==NULL)
            return res;
        int flag=0;TreeNode* tp=root;
        while(tp||st2.size())
        {
            while(tp)
            {
                st2.push(tp);
                st1.push(0);
                tp=tp->left;
            }
            tp=st2.top();st2.pop();flag=st1.top();st1.pop();
            if(flag==0)
            {
                st2.push(tp);st1.push(1);tp=tp->right;
            }
            else if(flag==1)
            {
                res.push_back(tp->val);tp=NULL;
            }
        }
        return res;
    }
};
```