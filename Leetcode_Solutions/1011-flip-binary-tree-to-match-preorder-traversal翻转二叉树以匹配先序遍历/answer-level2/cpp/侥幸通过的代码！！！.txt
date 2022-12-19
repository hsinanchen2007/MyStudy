### 解题思路
当前不匹配就调转左右节点

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
    vector<int> res;int flag=0;int count=0;
    void rev(TreeNode* root,vector<int> voyage,vector<int> &res)
    {
        if(root)
        {
            if(root->val!=voyage[count])
            {
                flag=1;
                return;
            }
            else
            {
                if(root->left)
                {
                    if(root->left->val==voyage[count+1])
                    {
                        count++;
                        rev(root->left,voyage,res);
                    }
                    else
                    {
                        res.push_back(root->val);
                        TreeNode* temp=root->left;
                        root->left=root->right;
                        root->right=temp;
                        if(root->left)
                        {
                            ++count;
                            rev(root->left,voyage,res);
                        }
                    }
                }
                if(root->right)
                {
                    if(root->right->val==voyage[count+1])
                    {
                        count++;
                        rev(root->right,voyage,res);
                    }
                    else
                    {
                        flag=1;
                        return;
                    }
                }
            }
        }
    }
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        rev(root,voyage,res);
        if(flag==1)
        {
            res.clear();
            res.push_back(-1);
        }
        return res;
    }
};
```