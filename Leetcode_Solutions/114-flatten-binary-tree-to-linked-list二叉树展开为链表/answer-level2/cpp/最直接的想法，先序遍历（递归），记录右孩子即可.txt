由题意，链表的节点顺序是二叉树先序遍历的结果，通过右孩子指针连接，左孩子置为空。故，可直接按照先序遍历的思想，递归求解。具体如下：
- 使用哑节点，作为链表的尾部
- 在Core中，将链表尾节点的左孩子置为空，右孩子置为当前节点，尾节点后移
- 如果当前节点的左孩子不空，将左孩子连接到链表尾
- 如果当前节点的右孩子不空，将右孩子连接到链表尾

需要注意几点：
- 当前节点的右边插入了其左子树后，原先的右孩子信息将会丢失，故需要提前记录
- tail传入的是引用，因为在Core中会后移。如果是值传递，比如，使用题目描述的树，加入3后，回到节点2，如果是值传递，当前尾节点为2，插入4发生错误，而传引用，当前尾节点为3，插入4，正确
- Core中，尾节点后移，所以，dummyHead直接指向了root,而不是哑节点-1，所以要另外记录并释放
```
class Solution {
public:
    void flatten(TreeNode* root) {
        // 由题意，按前序遍历展开
        // 1.
        if (root == nullptr)
            return;

        // 2.
        TreeNode *dummyHead = new TreeNode(-1);
        TreeNode *tail = dummyHead;  // dummyHead传的是引用，在core指向root，故单独记录dummyHead

        // 传入链表尾部和root,将root树连接到链表尾部
        Core(root, tail);

        root = tail;  // tail在core中自增，指向了root

        // 释放dummyHead
        root = dummyHead->right;
        delete dummyHead;
        dummyHead = nullptr;

        return;
    }
    void Core(TreeNode *root, TreeNode *&tail) {  // 传入引用，在core直接修改tail，否则，比如插入3之后回到2，tail仍为2，不合题意
        TreeNode *right = root->right;  // 后面操作，在当前节点的右边插入了其左子树，故提前记录有孩子信息

        // 当前节点
        tail->left = nullptr;
        tail->right = root;
        tail = tail->right;

        if (root->left != nullptr) {
            Core(root->left, tail);
        }
        if (right != nullptr) {
            Core(right, tail);
        }
    }
};
```
如果，能优化本代码，欢迎留言。