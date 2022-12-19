

代码实在太优美！！！
```
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* node1 = headA, * node2 = headB;
        while(node1 != node2){
            node1 = node1 ? node1->next:headB;
            node2 = node2 ? node2->next:headA;
        }
        return node1;
    }
};
```

代码2:
```
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL) return NULL;

        ListNode* head1 = headA, * head2 = headB;
        int m = 0, n = 0;
        while(head1){
            ++m;
            head1 = head1->next;
        }
        while(head2){
            ++n;
            head2 = head2->next;
        }

        int step = m>n ? m-n:n-m;
        ListNode* fast = m>n ? headA : headB;
        ListNode* slow = m>n ? headB : headA;
        while(step--){
            fast = fast->next;
        }
        while(fast && slow){
            if(fast == slow) break;
            fast = fast->next;
            slow = slow->next;
        }
        if(fast == slow) return fast;
        else return NULL;
    }
};
```
