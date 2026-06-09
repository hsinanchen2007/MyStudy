方法1.**递归**
寻找链表的中点，然后取中点为根节点，因为链表本身有序，所以中点一分为二的两个子链表也有序，故可以将原问题化为两个子问题递归。

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) return nullptr;
        if (!head->next){
            TreeNode* root=new TreeNode(head->val);
            return root;
        }
        ListNode *temp,*newhead;
        ListNode *first=head;
        ListNode *second=head;
        while (first&&first->next)
        {
            first=first->next->next;
            temp=second;
            second=second->next;
        }
        temp->next=nullptr;
        TreeNode *root=new TreeNode(second->val);
        newhead=second->next;
        root->left=sortedListToBST(head);
        root->right=sortedListToBST(newhead);
        return root;
    }
};