
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
    int findSecondMinimumValue(TreeNode* root) {
        set<int> had;
        //中序遍历，获得树中所有节点的值
        help(had,root);
        if(had.size()<2) return -1;
        return *(++had.begin());
    }

    void help(set<int>& had,TreeNode* root)
    {
        if(root!=NULL)
        {
            help(had,root->left);
            had.insert(root->val);
            help(had,root->right);
        }
    }
};
```