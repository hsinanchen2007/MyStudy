### 解题思路
在层次遍历，按层输出的基础上，增加flag监控，flag==0由左到右正向输出，flag==1由右到左逆向输出，只需将vector<int>反序；

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
        if(!root) return {};
        TreeNode* p = root;
        TreeNode* last = root;
        queue<TreeNode*> que; que.push(root);
        vector<vector<int>> leor = {{root->val}};
        vector<int> le;
        int flag = 1;
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
                if(flag == 1)         //flag==1则该层反向
                    reverse(le.begin(), le.end());
                flag = flag==0 ? 1 : 0; //更改flag
                leor.push_back(le);
                le.clear();
            }
        }
        return leor;
    }
};
```