先转换为最坏情况的二叉搜索树，即所有节点都只有右孩子，可以看作一条斜向下的链表，然后递归的转换为平衡二叉树


```
class Solution {
public:
    TreeNode* balanceBST(TreeNode* root) {
        TreeNode* head = new TreeNode(-1);
        TreeNode* tail = head;
        int n = inorderVisit(root, tail);
        tail = NULL;
        return turn(head->right, tail, n);
    }
    int inorderVisit(TreeNode* root, TreeNode* &last){           //将二叉搜索树变为最坏情况，所有节点都只有右孩子，顺便计算节点数
        int l = 0, r = 0;
        if(root->left)
            l = inorderVisit(root->left, last);
        last->right = root;
        last = root;
        if(root->right)
            r = inorderVisit(root->right, last);
        return l+r+1;
    }
    TreeNode* turn(TreeNode* head, TreeNode* &nextRoot, int n){  //每次将中间的节点作为根节点，将左右子树转为平衡二叉树，n为当前子树节点数
        if(n == 0){                                     //用一个指针引用nextRoot在转平衡二叉树的同时记录下一个作为根节点的节点，这样不用每次都循环来找根节点
            nextRoot = head;
            return NULL;
        }
        int ln = n>>1 ,rn = n-1-ln;
        TreeNode *left = turn(head, nextRoot, ln);              //将左子树转为平衡二叉树后，nextRoot会指向当前子树的根节点
        TreeNode *root = nextRoot;
        TreeNode *right = turn(nextRoot->right, nextRoot, rn);  //将右子树转为平衡二叉树后，nextRoot会指向当下一次要转换的子树的根节点
        root->left = left;
        root->right = right;
        return root;
    }
};
```


