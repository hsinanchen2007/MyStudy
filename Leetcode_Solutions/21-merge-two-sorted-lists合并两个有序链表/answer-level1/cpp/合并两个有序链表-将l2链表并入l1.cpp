执行用时 :8 ms, 在所有 C++ 提交中击败了98.02%的用户

内存消耗 :8.9 MB, 在所有 C++ 提交中击败了83.79%的用户

修改并返回l1链表。
```
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL)
            return l2;
        if(l2 == NULL)
            return l1;
        ListNode *l2_ = l2;
        if(l2->val < l1->val)
        {
            l2_ = l2_->next;
            l2->next = l1;
            l1 = l2;
        }
        ListNode *temp_1 = l1;
        ListNode *t;
        while(temp_1!=NULL && l2_!=NULL)
        {
            while(temp_1->next!=NULL &&temp_1->next->val <= l2_->val)
                temp_1 = temp_1->next;
            t = l2_;
            l2_ = l2_->next;
            t->next = temp_1->next;
            temp_1->next = t;
        }
        return l1;
    }
};
```
