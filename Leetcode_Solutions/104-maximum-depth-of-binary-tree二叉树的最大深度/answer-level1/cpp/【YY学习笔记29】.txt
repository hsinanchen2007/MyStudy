### 解题思路
递归实现。
### 知识点
1.DFS（等做到“图”的题目再说）
2.BFS（等做到“图”的题目再说)
### 感悟
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
        //深度优先遍历（DFS
        if(root==NULL){
            return 0;
        }
        else{
            int depthl=maxDepth(root->left);
            int depthr=maxDepth(root->right);
            if(depthl>depthr)
                return depthl+1;
            else
                return depthr+1;
        }
    }
};
```