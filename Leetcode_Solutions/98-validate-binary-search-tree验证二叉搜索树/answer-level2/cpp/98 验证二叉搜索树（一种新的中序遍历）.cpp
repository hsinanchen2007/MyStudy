### 解题思路
思路很简单：
首先使用一个队列将递归中序遍历的结果保存在里面（注意递归终止条件）
最后一边出队一边判断是否是升序

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
private:
    queue<int>& traverseBst(queue<int>&st,TreeNode *root)
    {      
        if(root)
        {
         traverseBst(st,root->left);
         st.push(root->val);
         traverseBst(st, root->right);
         return st;
        }
        return st;
    }

public:
    bool isValidBST(TreeNode* root)
    {
        if(root==NULL)
         return true;

        queue<int>st;
        st=traverseBst(st, root);
        while(st.size()>1)
        {
            int s=st.front();
            st.pop();
            if(st.front()<=s)
            return false;
        }
     return true;  
    }
};
```