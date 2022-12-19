1 递归实现

```
class Solution {
public:

    void helper(TreeNode* root,vector<int>& result)
    {
        if(root==NULL)
        {
            return ;
        }
        else
        {
            helper(root->left,result);
            result.push_back(root->val);
            helper(root->right,result);
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
       vector<int> result;
       helper(root,result);
       return result;
    }
};
```


2 用辅助栈递归实现


```
class Solution {
public:
    void helper(TreeNode* root,vector<int>& result)
    {
        if(root==NULL)
        {
            return;
        }
        else
        {
            stack<TreeNode*> sta;
            while(!sta.empty()||root!=NULL)
            {
                if(root!=NULL)
                {
                    sta.push(root);
                    root=root->left;
                }
                else
                {
                    root=sta.top();
                    result.push_back(root->val);
                    sta.pop();
                    root=root->right;
                }
            }
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        helper(root,result);
        return result;
    }
};
```
