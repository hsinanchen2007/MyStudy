
```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int len = lists.size();
        if (len == 0) return NULL;
        int interval = 1;
        while (interval < len) {
            for (int i = 0; i < len - interval; i += 2 * interval) {
                lists[i]  = mergeTwoList(lists[i], lists[i + interval]);
            }
            interval *= 2;
        }

        return lists[0];
    }

    ListNode* mergeTwoList(ListNode* l1,ListNode* l2){
        ListNode* head = new ListNode(1);
        ListNode* ret = head;
        while(l1 != NULL&& l2 !=NULL){
            if(l1->val > l2->val){
                head->next = l2;
                l2 = l2->next;
            }else{
                head->next = l1;
                l1 = l1->next;
            }
            head = head->next;
        }
        head->next = l1 == NULL?l2:l1;
        return ret->next;
    }
};
```