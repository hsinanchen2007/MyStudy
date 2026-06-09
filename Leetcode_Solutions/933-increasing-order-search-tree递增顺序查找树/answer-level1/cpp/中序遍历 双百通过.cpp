### 解题思路
利用中序遍历的性质：二叉搜索树的中序遍历得到一个递增的序列。
然后根据要求构建一棵树：
先定义一个节点ans，用于返回整棵树
在定义一个节点cur，表示正在操作的节点。按照题目要求，只需要根据数组中的值，依次在右子树中构造相应的节点即可。

![1.png](https://pic.leetcode-cn.com/040dee196802ca21dc32807e6c39d2c3223f6c8c63b374dc3f8ea36e319fce37-1.png)


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
    void inOrder(TreeNode* root,vector<int> &res)
    {
        if(root==NULL)  return ;
        inOrder(root->left,res);
        res.push_back(root->val);
        inOrder(root->right,res);
    }
    TreeNode* increasingBST(TreeNode* root) {
        vector<int> res;
        inOrder(root,res);
        TreeNode *ans = new TreeNode(0),*cur=ans;
        for(int v:res)
        {
            cur->right = new TreeNode(v);
            cur=cur->right;
        }
        
        return ans->right;
    }
};
```