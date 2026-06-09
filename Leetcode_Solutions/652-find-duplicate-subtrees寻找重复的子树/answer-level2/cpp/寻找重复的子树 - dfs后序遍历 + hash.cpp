### 解题思路
前序和后序都可以，中序不行。

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
    unordered_map<string , int> um_cnt_ ;
    vector<TreeNode*> res_ ;

public:
    string dfs(TreeNode* node){
        if(node==NULL) return string("_");
        
        string str0 = dfs(node->left) ;
        string str2 = dfs(node->right);

        string str1 = str0 + str2 + to_string(node->val)  ;

        um_cnt_[str1]++ ;
        if(um_cnt_[str1] == 2) 
            res_.push_back(node) ;

        return str1 ;    
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        if(root==NULL) return res_;

        dfs(root) ;

        return res_ ;
    }
};

```