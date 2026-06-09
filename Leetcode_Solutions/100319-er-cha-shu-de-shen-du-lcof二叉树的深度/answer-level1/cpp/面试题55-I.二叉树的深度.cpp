### 解题思路
- 核心要点：设置两个全局变量count和depth，count记录递归过程中的路径长度，depth保存递归中的最大count
- 执行用时：8 ms, 在所有 C++ 提交中击败了92.60%的用户
- 内存消耗：18.9 MB, 在所有 C++ 提交中击败了100.00%的用户
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
    int count;
    int depth;
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL)return 0;
        depth=count=0;
        recur(root);
        return depth;
    }
    void recur(TreeNode*root){
        if(root!=NULL){
            count++;
            depth=max(depth,count);
            recur(root->left);
            recur(root->right);
            count--;
        }
    }
};
```