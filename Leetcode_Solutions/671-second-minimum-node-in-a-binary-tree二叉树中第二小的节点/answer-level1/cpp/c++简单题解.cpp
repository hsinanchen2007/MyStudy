### 解题思路
执行结果：通过 显示详情
执行用时 :0 ms, 在所有 cpp 提交中击败了100.00%的用户
内存消耗 :8.4 MB, 在所有 cpp 提交中击败了95.80%的用户

遍历二叉树，找到最小的2个值，返回2个值中的较大值

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
    int res=-1;
    int m=-1;
    void dfs(TreeNode* root)
    {
        if(!root)
            return ;
        if(res==-1||m==-1)
        {
            if(res==-1)
                res=root->val;
            else if(m==-1&&root->val>res)
            {
                m=root->val;
            }
            else if(m==-1&&root->val<res)
            {
                m=res;
                res=root->val;
            }   
        }
        else{
            if(root->val<m&&root->val>res)
            {
                m=root->val;
            }
            else if(root->val<res)
            {
                m=res;
                res=root->val;
            }
            
        }
        //cout<<res<<','<<m<<endl;
        dfs(root->left);
        dfs(root->right);
        
    }
    int findSecondMinimumValue(TreeNode* root) {
        dfs(root);
        //cout<<res<<','<<m<<endl;
        if(res==-1||m==-1)    return -1;
        return max(res,m);
    }
};
```