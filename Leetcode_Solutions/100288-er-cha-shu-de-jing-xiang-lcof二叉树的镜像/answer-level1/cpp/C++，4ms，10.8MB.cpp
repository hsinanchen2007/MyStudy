简单题，有一个坑是输入为空，if单独列出来就好，接下来就是简单的递归，如果某个节点有左子树，那么求它的这个左子节点下的结构镜像，右边同理，跳出递归的条件是某个节点既没有左子节点也没有右子节点，注意一下递归函数的顺序就好了

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
    TreeNode* mirrorTree(TreeNode* root) {
        if(root == NULL){
            return root;
        }
        TreeNode* result = root;
        left_right(root);
        return root;
    }
    void left_right(TreeNode *node){
        TreeNode *temp;
        if(!node->left && !node->right){
            return ;
        }
        if(node->left && node->right){
            left_right(node->left);
            left_right(node->right);
            temp = node->left;
            node->left = node->right;
            node->right = temp;
        }
        else if(node->left && node->right == NULL){
            left_right(node->left);
            temp = node->left;
            node->left = node->right;
            node->right = temp;
        }
        else if(node->right && node->left == NULL){
            left_right(node->right);
            temp = node->left;
            node->left = node->right;
            node->right = temp;
        }
    }
};
```

