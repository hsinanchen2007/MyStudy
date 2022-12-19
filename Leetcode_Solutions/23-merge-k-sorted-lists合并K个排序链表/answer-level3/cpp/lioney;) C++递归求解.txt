```
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;
        return helper(lists, 0, lists.size()-1);
    }
    ListNode* helper(vector<ListNode*>& lists, int l, int r) {
        if(r - l < 1) return lists[l];
        int mid = l + (r - l) / 2;
        return mergeTwoLists(helper(lists, l, mid), helper(lists, mid+1, r));
    }
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(0);
        ListNode *cur = dummy;
        while(l1 && l2)
        {
            if(l1->val <l2->val)
            {
                cur->next = l1;
                l1 = l1->next;
            }
            else{
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        cur->next = l1 ? l1 :l2;//处理l1或者l2有剩余的情况
        return dummy->next;
    }
};

```
