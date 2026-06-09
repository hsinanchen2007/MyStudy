### 解题思路
此处撰写解题思路

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
    TreeNode* buildTree(vector<int>& pre, vector<int>& mid) 
    {
        if(pre.empty()) return NULL;

        TreeNode* root=new TreeNode(pre[0]);
        int root_pos;  //根结点在中序遍历中的位置

        for(int i=0;i<mid.size();i++)
        {
            if(mid[i]==root->val)
            {
                root_pos=i;
                break;
            }
        }

        if(root_pos>0)
        {
            vector<int> pre1(&pre[1],&pre[root_pos]+1);
            vector<int> mid1(&mid[0],&mid[root_pos]);
            root->left=buildTree(pre1,mid1);
        }

        if(root_pos<mid.size()-1)
        {
            vector<int> pre2(&pre[1+root_pos],&pre[pre.size()-1]+1);
            vector<int> mid2(&mid[root_pos+1],&mid[mid.size()-1]+1);
            root->right=buildTree(pre2,mid2);
        }
        
        return root;
    }
};
```