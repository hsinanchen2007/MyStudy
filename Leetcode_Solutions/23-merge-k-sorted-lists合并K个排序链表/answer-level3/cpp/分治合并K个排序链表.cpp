```
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;
        ListNode* pre = new ListNode(0);
        ListNode* cur = pre;
        while (l1 != NULL && l2 != NULL) {
            if (l1->val <= l2->val) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }

        cur->next = l1 != NULL ? l1 : l2;

        return pre->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int len = lists.size();
        if (len == 0) return NULL;
        // 分组间隔每次扩大两倍
        int interval = 1;
        while (interval < len) {
            // 根据当前间隔，两两合并，合并后的结果保存在两个链表的第一个
            for (int i = 0; i < len - interval; i += 2 * interval) {
                lists[i]  = mergeTwoLists(lists[i], lists[i + interval]);
            }
            interval *= 2;
        }

        return lists[0];
    }
};
```
