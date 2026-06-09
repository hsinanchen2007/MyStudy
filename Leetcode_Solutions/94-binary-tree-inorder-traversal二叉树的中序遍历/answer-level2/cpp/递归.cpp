```
class Solution {
public:
    void help(TreeNode* root, vector<int> &treevaluehelp) {
        if(root == NULL) { 
            return;
        }
        help(root->left, treevaluehelp);
        treevaluehelp.push_back(root->val);
        help(root->right, treevaluehelp);
        return;
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> treevalue;
        help(root, treevalue);
        return treevalue;
        }
    
};
```
![image.png](https://pic.leetcode-cn.com/6b539ca4d012f15514c8523dbf4096f12d9222c9a58a294a23b532bdbe310251-image.png)

