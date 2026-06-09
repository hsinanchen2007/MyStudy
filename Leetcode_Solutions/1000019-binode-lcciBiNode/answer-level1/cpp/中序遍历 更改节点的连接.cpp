### 解题思路
先定义一个节点ans用来返回整棵树，定义另一个节点cur=ans，用来表示正在遍历的节点的上一个节点。
进行中序遍历，每遍历到一个节点时，就将它的左孩子设为NULL，然后将它身作为上一个节点的右孩子。

### 代码
```
class Solution {
public:
    TreeNode *ans = new TreeNode(0),*cur=ans;
    void inOrder(TreeNode* node)
    {
        if(node==NULL)  return ;
        inOrder(node->left);
        node->left=NULL;    //将该节点的左孩子设为NULL
        cur->right=node;    //将该节点赋给上一个节点的右孩子
        cur=node;           //更新cur
        inOrder(node->right);
    }
    TreeNode* convertBiNode(TreeNode* root) {
        inOrder(root);
        return ans->right;
    }
};
```
