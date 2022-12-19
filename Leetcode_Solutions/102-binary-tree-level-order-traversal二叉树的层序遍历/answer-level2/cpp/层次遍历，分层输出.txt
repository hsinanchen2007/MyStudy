### 解题思路
层次遍历，增加一个last指针，指向每层的最后一个元素，按层将数据存入vector<int>中

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
        if(!root) return {};
        TreeNode* p = root;
        TreeNode* last = root;
        queue<TreeNode*> que;
        que.push(p);
        vector<vector<int>> leor = {{root->val}};
        vector<int> le;
        while(!que.empty())
        {
            p = que.front(); que.pop();
            if(p->left)
            {
                que.push(p->left);
                le.push_back(p->left->val);
            }
            if(p->right)
            {
                que.push(p->right);
                le.push_back(p->right->val);
            }
            if(p == last && !que.empty())
            {
                last = que.back();
                leor.push_back(le);
                le.clear();
            }
        }
        return leor;
    }
};
```