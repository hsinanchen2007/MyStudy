### 解题思路
递归还原二叉树，并在该过程中用哈希表记录出现过的元素便于查找

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
    unordered_map<int,bool>hash;
    FindElements(TreeNode* root) {
        root->val=0;
        dfs(root);
    }
    void dfs(TreeNode* root){
        if(!root)return; 
        hash[root->val]=1;
        if(root->left){
            root->left->val = root->val*2+1;
            dfs(root->left);
        }
        if(root->right){
            root->right->val = root->val*2+2;
            dfs(root->right);
        }
    }
    bool find(int target) {
        return hash[target];
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
```