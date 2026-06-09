也不要断了在连回去
```
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head, ListNode *stop=nullptr) {
        if (!head || head == stop) return nullptr;
        auto mid = get_mid(head, stop);
        auto rt = new TreeNode(mid->val);
        if (head == mid) return rt;
        rt->left = sortedListToBST(head, mid);
        rt->right = sortedListToBST(mid->next, stop);
        return rt;
    }
    ListNode *get_mid(ListNode *head, ListNode *stop = nullptr) { 
        auto f = head, s = head;
        while (f != stop && f->next != stop) {
            f = f->next->next;
            s = s->next;
        }
        return s;
    }
};  
```