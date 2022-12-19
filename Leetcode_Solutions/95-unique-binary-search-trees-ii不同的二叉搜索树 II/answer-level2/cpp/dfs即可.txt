### 解题思路
这题和上一题思路基本一样。枚举根节点即可。
写起来比较麻烦。如果熟悉二重指针的话，可以用二重指针来代替vector<TreeNode*> 。用二重指针的话，空间就优化下来了。不过二重指针还是谨慎使用。

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
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> vec;
        if(n==0) return vec;
        return dfs(1,n);
    }
   vector<TreeNode*> dfs(int l,int r)
    {
        if(l>r)
        {
            vector<TreeNode*> vec;
            TreeNode *tmp=NULL;
            vec.push_back(tmp);
            return vec;
        }
        else if(l==r)
        {
            TreeNode *tmp=new TreeNode(l);
            vector<TreeNode*> vec;
            vec.push_back(tmp);
            return vec;
        }
        else
        {
            vector<TreeNode*> vec;
            for(int i=l;i<=r;i++)
            {
                TreeNode *root=new TreeNode(i);
                vector<TreeNode*> left=dfs(l,i-1);
                vector<TreeNode*> right=dfs(i+1,r);
                for(auto lt:left)
                {
                    for(auto rt:right)
                    {
                        TreeNode *tmp=new TreeNode(i);
                        tmp->left=lt;
                        tmp->right=rt;
                        vec.push_back(tmp);
                    }
                }
            }
            return vec;
        }
    }
};
```