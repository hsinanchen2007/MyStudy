```
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
    vector<int> visit(vector<TreeNode*>&a)
    {
        vector<TreeNode*>b=a;
        vector<int>result;
        for(int i(0);i<b.size();i++)
        {
            if(b[i]->left!=NULL)
                a.push_back(b[i]->left);
            if(b[i]->right!=NULL)
                a.push_back(b[i]->right);
            result.push_back(b[i]->val);
            a.erase(a.begin());    
        }
        return result;
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<TreeNode*>a;
        a.push_back(root);
        vector<vector<int>>result;
        if(root==NULL)
            return result;
        int flag=1;
        while(a.size()!=0)
        {
            if(flag%2==1)
            {
                result.push_back(visit(a));
            }
            else
            {
                vector<int>l=visit(a);
                reverse(l.begin(),l.end());
                result.push_back(l);
            }
            flag++;
        }
        return result;
    }
};
```
简单明了的写法