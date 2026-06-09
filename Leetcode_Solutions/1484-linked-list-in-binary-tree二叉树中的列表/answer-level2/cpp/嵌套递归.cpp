```c++
class Solution {
public:
    // match 函数的作用为判断以 head 为头结点的链表和以 root 为根节点的链表是否匹配
    bool match(ListNode* head, TreeNode* root) {
        if (!head) {    // 链表没了，匹配成功
            return true;
        }
        if (!root) {    // 链表还有，二叉树没了，匹配失败
            return false;
        }
        if (head->val == root->val) {   // 根节点和头结点相等，继续遍历
            return match(head->next, root->left) || match(head->next, root->right);
        }
        return false;
    }

    // isSubPath 函数的作用是利用先序遍历进行匹配
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (match(head, root)) {    // 匹配成功
            return true;
        }
        if (root->left && isSubPath(head, root->left)) {    // 匹配左子树
            return true;
        }
        if (root->right && isSubPath(head, root->right)) {  // 匹配右子树
            return true;
        }
        return false;
    }
};
```