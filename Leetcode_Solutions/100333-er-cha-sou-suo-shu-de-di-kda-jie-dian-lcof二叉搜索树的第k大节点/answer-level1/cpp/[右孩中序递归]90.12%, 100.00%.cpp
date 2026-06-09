### 解题思路
肥肠费解。。。递归这么好理解的东西为什么题解里那么多人在造迭代？？？
执行用时 : 20 ms, 在所有 C++ 提交中击败了90.12%的用户
内存消耗 : 27.1 MB, 在所有 C++ 提交中击败了100.00%的用户

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
private:
    vector<int> v;
public:
    int kthLargest(TreeNode* &root, int k) {
        //no limit on size -> complete srch
        helper(root);        
        return v[--k];
    }
    void helper(TreeNode* &root){
        if (root == NULL)
            return;        
        helper(root->right);                    
        v.emplace_back(root->val);
        helper(root->left);
    }
};
```