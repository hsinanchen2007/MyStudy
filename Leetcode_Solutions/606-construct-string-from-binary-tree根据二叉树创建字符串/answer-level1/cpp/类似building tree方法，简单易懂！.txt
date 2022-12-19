
```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
```
```
//1、右子树的空括号是无效括号。
//2、左子树的空括号需要保留。
//3、左子树叶子节点之后的左节点也不用加括号。
```
 ```
string DFS(TreeNode* root){
     if(!root) return "";
     string str=to_string(root->val);
     if(root->left||root->right)//左子树排除叶子节点
     str+="("+DFS(root->left)+")";//遍历左子树
     if(root->right){//排除右子树空括号
         str+="("+DFS(root->right)+")";//遍历右子树
     }
     return str;
 }
class Solution {
public:
    string tree2str(TreeNode* t) {
        if(!t) return "";
        return DFS(t);
    }
};
```