道理大家应该都懂，二叉搜索树中序遍历有序
设置一个pre节点作为当前node节点的**前驱**
然后套用中序遍历
记得每次更新pre
```
class Solution {

    TreeNode* head= new TreeNode(0);
    TreeNode* pre = head;
    void f(TreeNode* node){
        if(!node) return;
        f(node->left);
        node->left = NULL;
        pre->right = node;
        pre = node;
        f(node->right);
    }
public:
    TreeNode* convertBiNode(TreeNode* root) {
        if(!root ) return NULL;
        f(root);
        return head->right;
    }
};
```
