### 解题思路
对与关于求创建二叉树的问题一般都是需要先求左右子树，在本题中求所有不同的搜索二叉树，那么我们应该先求以某一个数为根结点时，它的左右子树各有多少不同的树，同理对于左右子树而言我们依然求他们各自的左右子树各有多少种，那么左右子树的笛卡儿积数便是以某一个数为根节点时的二叉搜索树的总个数。对于每一个数为根节点时都套用相同的方法，因此我们可以用一个递归来实现该算法。在每次递归返回时，返回的数组记录的是左右子树的不同树。

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
        if(n==0)
        {
            return vector<TreeNode*>();
        }
        return trees(1,n);
    }
    vector<TreeNode*> trees(int start,int end)
    {
        vector<TreeNode*> search_tree;
        if(start>end)
        {
            search_tree.push_back(NULL);
            return search_tree;
        }
         for(int i=start;i<=end;i++)
        {
            vector<TreeNode*>left_tree=trees(start,i-1);
            vector<TreeNode*>right_tree=trees(i+1,end);
            for(auto item_left:left_tree)
            {
                for(auto item_right:right_tree)
                {
                    TreeNode *root=new TreeNode(i);
                    root->left=item_left;
                    root->right=item_right;
                    search_tree.push_back(root);
                }
            }
        }
        return search_tree;
    }
};
```