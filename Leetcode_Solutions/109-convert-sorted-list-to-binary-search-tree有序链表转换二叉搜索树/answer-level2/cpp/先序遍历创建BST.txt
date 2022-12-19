首先遍历一遍计算链表长度。
```
class Solution {
    TreeNode *preorder(ListNode *head, int len){
        if(head==NULL || len==0) return NULL;
        ListNode *mid=head;
        for(int i=len>>1; i--; mid=mid->next);
        TreeNode *root=new TreeNode(mid->val);
        root->left=preorder(head,len>>1);
        root->right=preorder(mid->next,len-(len>>1)-1);
        return root;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        int len=0;
        for(ListNode *i=head; i; ++len, i=i->next);
        return preorder(head, len);
    }
};
```
