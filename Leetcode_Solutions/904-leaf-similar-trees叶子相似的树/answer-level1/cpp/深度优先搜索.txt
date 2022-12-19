### 解题思路
用两个vector数组存储两个树的叶子结点的值，然后比较两个数组。
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
    void Treenode(TreeNode* root, vector<int>& ints)
    {
        if(root != NULL)
        {
            if(root -> left == NULL && root -> right == NULL)
            {
                ints.push_back(root -> val);  //递归得到树的叶子结点的值
                return ;
            }
            Treenode(root -> left, ints);
            Treenode(root -> right, ints);
        }
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> r1, r2;
        Treenode(root1, r1);
        Treenode(root2, r2);
        if(r1.size() != r2.size()) return false;  //数组长度不一致，不相似
        else
           for(int i = 0; i < r1.size(); i ++)
              if(r1[i] != r2[i])  //数组内容不同，不相似
                 return false;
        return true;
    }
};
```