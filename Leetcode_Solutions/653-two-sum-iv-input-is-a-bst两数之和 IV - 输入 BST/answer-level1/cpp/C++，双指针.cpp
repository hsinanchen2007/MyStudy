### 解题思路
遍历放入数组，因为是二叉搜索树，中序遍历就是从小到大不用在排序。
然后双指针

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
    bool findTarget(TreeNode* root, int k) {
        vector<int> pool;
        dfs(root,pool);
        int i=0,j=pool.size()-1;
        while(i<j){
            if(pool[i]+pool[j]==k) return true;
            else if(pool[i]+pool[j]<k) i++;
            else j--;
        }
        return false;
    }
    void dfs(TreeNode* root,vector<int> &pool){
        if(root==NULL) return;  
        dfs(root->left,pool);
        pool.push_back(root->val);
        dfs(root->right,pool);
    }
};
```