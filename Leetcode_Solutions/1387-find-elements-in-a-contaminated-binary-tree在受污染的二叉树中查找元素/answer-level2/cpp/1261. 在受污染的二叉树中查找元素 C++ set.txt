### 解题思路
1.二叉树重新赋值：分别访问左右子树赋值
2.同时将val放入set，提升查找效率


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
class FindElements {
public:
    unordered_set<int> numset;
    void dfs(TreeNode* root){

        if(root->left != NULL){
            root->left->val = root->val * 2 + 1;
            numset.insert(root->left->val);
            dfs(root->left);
        }

        if(root->right != NULL){
            root->right->val = root->val * 2 + 2;
            numset.insert(root->right->val);
            dfs(root->right);
        }

        return;
    }

    FindElements(TreeNode* root) {
        if(root == NULL){
            return;
        }

        root->val = 0;
        dfs(root);

    }

    bool find(int target) {
        if(numset.count(target)){
            return true;
        }
        return false;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
```