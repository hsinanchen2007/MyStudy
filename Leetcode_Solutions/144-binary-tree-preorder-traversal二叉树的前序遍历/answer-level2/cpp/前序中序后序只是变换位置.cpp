```
class Solution {
public:
    void firsttraver(TreeNode* root, vector<int> &insertvector) {
        insertvector.push_back(root->val);
        if(root->left != nullptr) {
            firsttraver(root->left, insertvector);
        }
        if(root->right != nullptr) {
            firsttraver(root->right, insertvector);
        }
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> rootvalue;
        if(root != nullptr)
        firsttraver(root, rootvalue);
        return rootvalue;
    }
};
```
![image.png](https://pic.leetcode-cn.com/9ee23e12f18a5d9cc2eb1d9eaabe33816aac09f524de576ddf0ad85e086400fa-image.png)
