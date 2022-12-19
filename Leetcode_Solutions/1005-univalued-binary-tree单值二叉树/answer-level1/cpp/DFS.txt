### 解题思路
思路很多，这里我试试参数的
思路1.利用参数     思路2.通过全局变量来比较也行（将根节点的值给全局变量，递归时和这个全局变量比）

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
    bool isUnivalTree(TreeNode* root) {
        if(root==NULL) return true;
        return DFS(root,root->val);
    }
    bool DFS(TreeNode *root,int val){
        if(root==NULL) return true;
        return DFS(root->left,val)&&DFS(root->right,val)&&root->val==val;
    }
};
```