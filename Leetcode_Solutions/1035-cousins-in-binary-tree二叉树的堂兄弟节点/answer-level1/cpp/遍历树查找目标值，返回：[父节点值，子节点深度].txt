```C++
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
    // 返回：[父节点值，子节点深度]
    vector<int> getDepth(TreeNode* root, int node, int depth){
        vector<int> res;
        if(root == NULL) 
            return res;

        if(root->val == node)
        {
            res.push_back(-1);
            res.push_back(depth);
            return res;
        }
        else if((root->left && root->left->val == node) || (root->right && root->right->val == node)){
            res.push_back(root->val);
            res.push_back(depth+1);
            return res;
        }
        
        vector<int> left = getDepth(root->left, node, depth+1);
        if(left.empty() == false)
            return left;
        
        vector<int> right = getDepth(root->right, node, depth+1);
        if(right.empty() == false)
            return right;
        
        return res;
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
        vector<int> xDepth = getDepth(root, x, 0);
        vector<int> yDepth = getDepth(root, y, 0);
        if(!xDepth.empty() && !yDepth.empty() && xDepth[0] != yDepth[0] && xDepth[1] == yDepth[1])
            return true;
        else
            return false;
    }
};
```