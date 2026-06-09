### 解题思路
在力扣第102题的基础上，加上`reverse(res.begin(),res.end());`

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
class Solution 
{
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) 
    {
        vector<vector<int>> res;
        if(root==NULL)return res;
        queue<TreeNode*> myQueue;
        TreeNode* p;
        myQueue.push(root);

        while(!myQueue.empty())
        {
            vector<int> temp;
            int queueSize=myQueue.size();
            for(int i=0;i<queueSize;++i)
            {
                p=myQueue.front();
                myQueue.pop();
                temp.push_back(p->val);
                if(p->left!=NULL)
                    myQueue.push(p->left);
                if(p->right!=NULL)
                    myQueue.push(p->right);
            }
            res.push_back(temp);
        }
        reverse(res.begin(),res.end());
        return res;
    }


};
```