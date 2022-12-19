### 解题思路

**层序遍历模板**
```
void level(TreeNode* root)
{
    queue<TreeNode*> myQueue;
    if(root==NULL)return;

    myQueue.push(root);
    TreeNode* p=NULL;
        
    while(!myQueue.empty())
    {
        p=myQueue.front();
        myQueue.pop();

        visit(p);  /////处理

        if(p->left!=NULL)
            myQueue.push(p->left);
        if(p->right!=NULL)
            myQueue.push(p->right);
    }

```


**根据题意**
```
while(!myQueue.empty())
{
    int tempQueueSize=myQueue.size();
    vector<int> temp;

    for(int i=0;i<tempQueueSize;++i)
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
return res;
```


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
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        vector<vector<int>> res;
        queue<TreeNode*> myQueue;

        if(root==NULL)
            return res;

        myQueue.push(root);
        TreeNode* p=NULL;
        
        while(!myQueue.empty())
        {
            int tempQueueSize=myQueue.size();
            vector<int> temp;

            for(int i=0;i<tempQueueSize;++i)
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
        return res;
        
    }
};
```