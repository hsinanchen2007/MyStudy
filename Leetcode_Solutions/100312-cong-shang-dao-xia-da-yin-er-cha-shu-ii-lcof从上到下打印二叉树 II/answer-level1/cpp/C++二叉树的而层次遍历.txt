### 解题思路
利用两个队列解决层次遍历
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
 #include<vector>
 #include<queue>
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>res;
        if(root==NULL)return res;
        queue <TreeNode*> q;
        queue <TreeNode*> r;
        q.push(root);int i=0;
        while(!q.empty())
        {
            vector <int> re;int l=q.size();
           for(i=0;i<l;i++)
            {
            TreeNode*t=q.front();
            q.pop();
            re.push_back(t->val);

            if(t->left)r.push(t->left);
            if(t->right)r.push(t->right);
            }
            res.push_back(re);
            while(!r.empty())
            {
                q.push(r.front());
                r.pop();
            }
        }
        return res;

    }
};
