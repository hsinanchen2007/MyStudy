### 解题思路
如果为偶数行则顺序加入，如果为奇数行则将数字每次插入到最前面
因为要对res[level]操作，所以要res.resize(level+1)

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
    vector<vector<int>> res;   
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        addVector(root,0);      //调用递归函数
        return res;
    }
  
    void addVector(TreeNode* root,int level)
    {
        if(root == NULL)    return;
        if (res.size() == level)
            res.resize(level+1);//没有这个会出现内存异常
        if(level %2==0)                                     
            res[level].push_back(root->val);                //如果为偶数行则顺序加入，如果为奇数行则将数字每次插入到最前面
        else
            res[level].insert(res[level].begin(),root->val);

        addVector(root->left,level+1);
        addVector(root->right,level+1);          
    }
};



```