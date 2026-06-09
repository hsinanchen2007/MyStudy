### 解题思路
1、边界条件：root为空，则直接返回。
2、sum满足条件：则count++。
3、不需要从根节点开始，则需要两层遍历（把任何一个左子树或右子树也当成根节点）。

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
    int count = 0;
public:
    void DFS(TreeNode* root, int sum){
        if(!root){
            return;
        }
        if(root->val == sum){
            count++;
        }
        DFS(root->left, sum-root->val);
        DFS(root->right, sum-root->val);
    }
    int pathSum(TreeNode* root, int sum) {
        if(!root){
            return 0;
        }
        DFS(root, sum);
        if(root->left){
            pathSum(root->left, sum);
        }
        if(root->right){
            pathSum(root->right, sum);
        }
        return count;
    }
};
```