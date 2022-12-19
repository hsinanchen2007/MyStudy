![Screenshot from 2019-11-24 17-19-29.png](https://pic.leetcode-cn.com/18e28691120a658bfa7d0ceba3f69a13ebc29af9164ed138eeb3f797e80f2449-Screenshot%20from%202019-11-24%2017-19-29.png)
```c++
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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> us(to_delete.begin(), to_delete.end());
        vector<TreeNode*> result;
        delNodes1(root, us, result, false);
        return result;
    }
    TreeNode* delNodes1(TreeNode* t, unordered_set<int> &us, vector<TreeNode*> &result, bool hasParent) {
        if(t == nullptr){
            return nullptr;
        }
        TreeNode* ret;
        if(us.count(t->val) == 1){
            hasParent = false;
            ret = nullptr;
        } else{
            if(!hasParent){
                result.push_back(t);
            }
            hasParent = true;
            ret = t;
        }
        t->left = delNodes1(t->left, us, result, hasParent);
        t->right = delNodes1(t->right, us, result, hasParent);
        return ret;
    }
};
```
