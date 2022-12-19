### 解题思路
二叉搜索树的中序遍历为从小到达排列，如果采取中序遍历的对称操作，即先访问右节点，再访问根节点最后访问左子节点，遍历结果为从大到小排序，这时候只需要输出第`K-1`个值即为所求。

### 代码（递归）

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
    int kthLargest(TreeNode* root, int k) {
        // 中序遍历
        vector<int> res;
        dfs(res, root);
        return res[k - 1];
    }

    void dfs(vector<int>& res, TreeNode* root){
        if(root == nullptr) return;
        dfs(res, root->right);
        res.push_back(root->val);
        dfs(res, root->left);
    }
};
```

### 代码（非递归）
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
    int kthLargest(TreeNode* root, int k) {
        // 中序遍历
        vector<int> res;
        dfs(res, root);
        return res[k - 1];
    }

    void dfs(vector<int>& res, TreeNode* node){
        // 中序遍历非递归
        stack<TreeNode*> s;
        while(!s.empty() || node){
            // 当栈不为空，并且结点不为空
            while(node){
                // 当前节点不为空
                // 一直遍历到右子树最下面，边遍历边将节点压入栈
                s.push(node);  // 压入栈
                node = node->right; 
            }
            if(!s.empty()){
                // 已经访问到左子树最下面，这时候该出栈访问父节点了
                node = s.top();
                s.pop();
                res.push_back(node->val);
                node = node->left;
            }
        }
    }
};
```