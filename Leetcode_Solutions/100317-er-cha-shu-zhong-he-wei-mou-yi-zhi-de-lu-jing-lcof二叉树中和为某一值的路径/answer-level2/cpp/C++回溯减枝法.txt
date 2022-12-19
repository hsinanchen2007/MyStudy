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
    vector<vector<int>> res;
    vector<int> a;
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(root==nullptr) return res;
        findway(root,sum,0);
        return res;
    }
    void findway(TreeNode* root,int sum,int add)
    {
        if(root!=nullptr)
        {
            a.push_back(root->val);
            add=add+root->val;
            findway(root->left,sum,add);
            findway(root->right,sum,add);
            if(root!=nullptr&&root->left==nullptr&&root->right==nullptr&&add==sum)    res.push_back(a);
            //else这里不要写else！else的话if为真执行之后不会执行else，但是if真的话也要减val然后回溯
            {
                add=add-root->val;
                a.pop_back();
            }
        }

    }
};
```