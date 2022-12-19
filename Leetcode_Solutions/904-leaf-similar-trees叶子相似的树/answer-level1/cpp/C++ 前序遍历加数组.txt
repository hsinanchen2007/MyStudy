### 解题思路
对二叉树采用先根遍历，那么必然会正确的得到从左到右叶子节点的顺序序列，将这个序列保存在数组中，比较这两个数组是否相等即可

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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> l1;
        vector<int> l2;
        getleaf(root1,l1);
        getleaf(root2,l2);
        return l1==l2;
    }
private:
    void getleaf(TreeNode* root,vector<int>& leafs){
        if(!root)return;
        if(!root->left&&!root->right){
            leafs.push_back(root->val);
            return;
        }
        getleaf(root->left,leafs);
        getleaf(root->right,leafs);
    }
};
```