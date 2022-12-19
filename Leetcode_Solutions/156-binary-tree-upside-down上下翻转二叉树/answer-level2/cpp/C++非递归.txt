这道题很难理解意思，我是比着题目例子找的规律，但至今也没想明白为什么叫“翻转”？比较坑的地方是最后一个右节点是以前的根节点，注意最后要打断它的左右节点，否则有环运行会崩
```
class Solution {
public:
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if (root == NULL) {
            return NULL;
        }
        /*这个栈用来保存沿途的左节点，因为是翻转所以正好利用了陷入后出的特性*/
        stack<TreeNode*> stk;
        TreeNode* leftNode = root;  
        do {
            stk.push(leftNode);
            leftNode = leftNode->left;
        } while (leftNode != NULL); 
        
        TreeNode* rightNode = NULL;//这个用来向右建立子树的
        while(!stk.empty()) {
            TreeNode* curNode = stk.top();
            stk.pop();
            /*先建立根节点，栈顶是原树最下层的左节点，它肯定是没有左右节点的*/   
            if (curNode->left == NULL &&
                curNode->right == NULL) {
                    root = curNode;
                    rightNode = root;
            } else {
                rightNode->left = curNode->right;
                rightNode->right = curNode;
                rightNode = rightNode->right;//向右搜索
            }
        }
        /*最后这个右节点(1)是原树的根节点，现在要把它左右子树(2,3)给打断，否则会形成回环*/
        rightNode->left = NULL;
        rightNode->right = NULL;

        return root;
    }
};
```
