### 解题思路
1.通过数字n来构造不同的二叉搜索树，其中二叉搜索树是指其中序遍历为有序的。
2.数字1，2,3，...n可以作为根节点，其中根节点如果是i，则左子树可以为（1....i-1）,右子树为（i+1....n）。

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
    vector<TreeNode*> getTree(int begin, int end){
        vector<TreeNode*> res;
        if(begin >end){
            res.push_back(NULL);
            return res;
        }
        for(int i = begin; i<= end; i++){
            vector<TreeNode*> leftNode = getTree(begin, i-1);
            vector<TreeNode*> rightNode = getTree(i+1, end);
            for(auto left: leftNode){
                for(auto right: rightNode){
                    TreeNode* root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    res.push_back(root);
                }
            }
        }
        return res;
    }
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0){
            return vector<TreeNode*>();
        }
        return getTree(1, n);
    }
};
```