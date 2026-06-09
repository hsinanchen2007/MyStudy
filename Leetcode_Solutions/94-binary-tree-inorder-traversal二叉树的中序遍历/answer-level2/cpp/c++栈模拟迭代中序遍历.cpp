### 解题思路
先将根节点，以及根节点的左儿子，左孙子，左子子孙孙压入栈内，对于栈顶元素。
①将栈顶元素的值增加进数组，然后开始循环判断。
②如果栈顶节点存在右子树，则将右子树压入栈内，并且不断将右子树的左子孙压入栈内。
![image.png](https://pic.leetcode-cn.com/e53db82b60163cfdc385c697dd33892d3cdcdac38933af83ebe099959def3ea4-image.png)

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
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root) return {};
        vector<int> answer;
        stack<TreeNode*> sta;
        sta.push(root);
        while(root->left)
        {
            sta.push(root->left);
            root=root->left;
        }
        while(!sta.empty())
        {
            TreeNode* top=sta.top();
            answer.push_back(top->val);
            sta.pop();
            if(top->right)
            {
                top=top->right;
                sta.push(top);
                while(top->left)
                {
                    sta.push(top->left);
                    top=top->left;
                }
            }
        }
        return answer;
    }
};
```