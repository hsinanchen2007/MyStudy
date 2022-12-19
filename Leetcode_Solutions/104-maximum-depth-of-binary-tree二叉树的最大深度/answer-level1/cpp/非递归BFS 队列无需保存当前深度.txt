BFS的写法就不说了，这里主要说一下如何判断什么时候深度+1。
代码中引入了first这个指针变量，用来保存每一层最左边节点的地址。
当first为NULL时，保存遇到的第一个非空孩子
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
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        queue<TreeNode*> q;
        q.push(root);
        int depth = 0;
        TreeNode* first = root;
        while(!q.empty()){
            TreeNode *node = q.front();
            q.pop();
            if(first == node){
                depth += 1;
                first = NULL;
            }
            if(first == NULL){
                first = node->left;
            }
            if(first == NULL){
                first = node->right;
            }
            if(node->left != NULL){
                q.push(node->left);
            }
            if(node->right != NULL){
                q.push(node->right);
            }
        }
        return depth;
    }
};
```
