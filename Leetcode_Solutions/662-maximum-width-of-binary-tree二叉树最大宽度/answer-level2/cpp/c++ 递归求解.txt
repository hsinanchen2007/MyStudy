### 解题思路
res中每个深度第一个push_back的结点一定是树在某一深度的最左的结点，最后push的是该深度最右的节点，只要遍历0-n-1深度 找到最大即可

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
    map<int,int> tmp;
    int widthOfBinaryTree(TreeNode* root) {
        map<double,vector<double>> res;
        if(root==NULL)
            return 0;
        help(root,0.0,1.0,res);
        int n=res.size();
        int m=res[n-1].size();
        double ans=0.0;
        for(int i=0;i<n;i++)
        {
            ans=max(ans,res[i][res[i].size()-1]-res[i][0]+1.0);  
                    }

                    
        }
        return int(ans);
    }
    void help(TreeNode* root, double depth, double idx,map<double,vector<double>>& res)
    {
        if(root==NULL)
            return;
        res[depth].push_back(idx);
        help(root->left,depth+1,idx*2,res);
        help(root->right,depth+1,idx*2+1,res);
    }
};
```