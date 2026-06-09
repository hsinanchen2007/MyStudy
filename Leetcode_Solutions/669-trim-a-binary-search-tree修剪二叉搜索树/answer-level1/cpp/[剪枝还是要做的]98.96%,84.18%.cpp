### 解题思路
题解里不剪枝直接返回子节点的，相当于少打一行代码，单却把冗余推栈里了，遍历完再返回成品，区别如下
![跑分](https://pic.leetcode-cn.com/4ea0e353be25378543b77ccfd8da8b6e218e96cde99868b71b68f42fffbef4fb-Screenshot%202020-03-06%20at%205.23.18%20PM.png)


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
    TreeNode* trimBST(TreeNode* &root, int L, int R) {
        // all > complete srch then  pruning...
        // bst > pruning        
        return helper(root, L, R);;
    }
private:
    TreeNode* helper(TreeNode* &root, int L, int R){
        if (root == NULL)
            return NULL;  
        if (root->val < L){
            root->left = NULL;
            //cut root
            root = helper(root->right, L, R);
            return root;
        }
        if (root->val > R){
            root->right = NULL;
            //cut root
            root = helper(root->left, L, R);
            return root;
        }
        //relink here
        root->left = helper(root->left, L, R);
        root->right = helper(root->right, L, R);
        return root;
    }
};
```