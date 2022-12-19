```c++
class Solution {
public:
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        if(root->val == x) { //如果红方开局选了根节点，直接可以判断
            if(nodeCount(root->left) == nodeCount(root->right)) return false; //如果左右子树节点数相同，红方肯定比蓝方多1，必输
            else return true; //反之有一个子树超过半数，蓝方选这个子树必胜。
        }
        TreeNode* red = find(root, x); //找到红方选的节点
        int leftcount = nodeCount(red->left);
        int rightcount = nodeCount(red->right);
        if(1+leftcount+rightcount <= n / 2) return true; //如果红方选的节点为根的树的节点数<=n/2，则蓝方只需要选这个节点的父节点必胜，因为n是奇数。
        return leftcount > n/2 || rightcount > n/2; //否则如果红方选节点的左子树或右子树超过半数，蓝方就选左子树或右子树，必胜；反之必败
    }
    int nodeCount(TreeNode* root) {
        if(root == nullptr) return 0;
        return 1 + nodeCount(root->left) + nodeCount(root->right);
    }
    TreeNode* find(TreeNode* root, int x) {
        if(root == nullptr) return nullptr;
        if(root->val == x) return root;
        TreeNode* tmp = find(root->left, x);
        if(tmp != nullptr) return tmp;
        return find(root->right, x);
    }
};
```