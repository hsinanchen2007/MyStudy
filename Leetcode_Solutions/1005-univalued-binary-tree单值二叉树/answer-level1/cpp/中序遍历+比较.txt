### 解题思路
对树进行中序遍历，中序遍历的结果存入vector，再对vector相邻值比较是否相等。

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
 #include<vector>
class Solution {
public:
    void InOrder(TreeNode *x,vector<int> &v)
    {
        if(!x)return;
        InOrder(x->left,v);
        v.push_back(x->val);
        InOrder(x->right,v);
    }
    bool isUnivalTree(TreeNode* root) {
        if(!root)return true;
        vector<int> temp;
        InOrder(root,temp);
        for(int i=0;i<temp.size()-1;++i)
            if(temp[i]!=temp[i+1])return false;
        return true;
    }
};
```