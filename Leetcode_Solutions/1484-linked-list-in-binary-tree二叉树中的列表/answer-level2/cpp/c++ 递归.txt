```
class Solution {
public:
    bool isSubPath(ListNode* head, TreeNode* root) {//不能直接用isSubPath递归，必须先isSame，因为链表中间断开也符合
        if(head==NULL)return true;
        if(root==NULL)return false;
        return isSame(head,root)||isSubPath(head,root->left)||isSubPath(head,root->right);
    }
    bool isSame(ListNode* head, TreeNode* root){
        if(head==NULL)return true;
        if(root==NULL)return false;
        if(head->val!=root->val)return false;
        return isSame(head->next,root->left)||isSame(head->next,root->right);
    }
};
```
