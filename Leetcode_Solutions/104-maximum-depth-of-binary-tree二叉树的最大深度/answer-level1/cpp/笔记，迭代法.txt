### 解题思路
此处撰写解题思路
1. 如果一个节点有子节点，那么它的深度一定是 1 + 子节点的最大深度
2. 如果指针为空，显然深度是0
3. 在不断的迭代中，问题规模不断变小，直到到达最深的节点


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
    int maxDepth(TreeNode* root) {
        if(root == NULL) {
            return 0;
        } else {
            return 1 + max ( maxDepth(root->left) , maxDepth(root->right) );
        }
        
    }
};
```