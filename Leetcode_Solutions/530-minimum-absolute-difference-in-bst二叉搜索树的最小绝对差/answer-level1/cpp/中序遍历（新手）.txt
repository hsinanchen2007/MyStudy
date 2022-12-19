### 解题思路
由于是二叉搜索树，因此通过中序遍历可以得到一个递增的序列。之后易得树中任意两节点的差的绝对值的最小值。

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
    vector<int> uses;

    int getMinimumDifference(TreeNode* root) 
    {
        int res=INT_MAX,temp=0;
        if(root==NULL) return 0;
        help(root);
        for(int i=0;i<uses.size()-1;i++)
        {
            temp=uses[i+1]-uses[i];
            res=res>temp?temp:res;
        }
        return res;
    }

    //中序遍历
    void help(TreeNode* root)
    {
        if(root!=NULL)
        {
            help(root->left);
            uses.push_back(root->val);
            help(root->right);
        }
    }
};
```