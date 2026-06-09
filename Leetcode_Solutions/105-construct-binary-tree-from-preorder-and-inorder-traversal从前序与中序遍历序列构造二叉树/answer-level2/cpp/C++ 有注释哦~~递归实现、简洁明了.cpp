```
class Solution {
public:
    TreeNode* Creat(int preL, int preR, int inL, int inR, vector<int>& preorder, vector<int>& inorder) {
        if (preL > preR) {
            return NULL;
        }
        // 确定当前子树的跟节点
        TreeNode* root = new TreeNode(preorder[preL]);
        // 从中序遍历中找根节点将其分开为左子树和右子树
        int k;
        for (k = inL; k < inR; k++) {
            if (preorder[preL] == inorder[k]) {
                break;
            }
        }
        // 当前节点被分成左子树和右子树，然后递归左子树、右子树
        // 左子树的前序preL + 1, preL + numLeft  中序下标为inL, k
        // 右子树的前序preL + numLeft + 1, preR  中序下标为k + 1, inR
        int numLeft = k - inL;
        root->left = Creat(preL + 1, preL + numLeft, inL, k - 1, preorder, inorder);
        root->right = Creat(preL + numLeft + 1, preR, k + 1, inR, preorder, inorder);
        return root;
    }
    // 前序/后序/层次遍历 +  中序，才能唯一确定一颗二叉树
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* root = Creat(0, preorder.size() - 1, 0, inorder.size() - 1, preorder, inorder);
        return root;
    }
};
```
