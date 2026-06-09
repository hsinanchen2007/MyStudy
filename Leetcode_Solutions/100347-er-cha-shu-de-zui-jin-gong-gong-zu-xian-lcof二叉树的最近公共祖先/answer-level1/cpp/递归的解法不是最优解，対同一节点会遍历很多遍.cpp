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
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> AncestorsOfp;
        vector<TreeNode*> AncestorsOfq;
        if(FindAncestors(root,p,AncestorsOfp)
            &&FindAncestors(root,q,AncestorsOfq))
        {
            return FindLowestCommonNode(AncestorsOfp,AncestorsOfq);
        }
        return nullptr;
    }
    bool FindAncestors(TreeNode* root, TreeNode* target, 
                        vector<TreeNode*>& AncestorsOfTarget)
    {
        AncestorsOfTarget.push_back(root);
        if(root==target)
            return true;
        if(root->left!=nullptr)
        {
            if(FindAncestors(root->left,target,AncestorsOfTarget))
                return true;
        }
        if(root->right!=nullptr)
        {
            if(FindAncestors(root->right,target,AncestorsOfTarget))
                return true;
        }
        AncestorsOfTarget.pop_back();
        return false;
    }
    TreeNode* FindLowestCommonNode(vector<TreeNode*> NodesOfp,
                                vector<TreeNode*> NodesOfq)
    {
        vector<TreeNode*>::iterator itp=NodesOfp.begin();
        vector<TreeNode*>::iterator itq=NodesOfq.begin();
        TreeNode* result;
        while(itp<NodesOfp.end()&&itq<NodesOfq.end()&&*itp==*itq)
        {
            result=*itp;
            itp++;
            itq++;
        }
        return result;
    }
};
```