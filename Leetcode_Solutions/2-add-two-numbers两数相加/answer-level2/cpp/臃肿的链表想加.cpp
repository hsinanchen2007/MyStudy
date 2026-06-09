
臃肿版本。 很久没写链表了。  最后写出来和题解意思一样。 就是有个dummyhead，多余的头结点来记住开始的指针头，才能找到这一串链表。  不过臃肿的部分可以优化的。 


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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int rk = 1;
        int pre = 0;
        ListNode * ans = new ListNode(0) ,* cur;
        cur = ans;
        while(l1 && l2){
            int now = l1->val + l2->val;
            now += pre;
            pre = 0;
            if(now >= 10){
                now = now %10;
                pre = 1;
            }
            ListNode* tmp  = new ListNode(now);
            cur ->next = tmp;
            cur = cur->next;
            l1 = l1->next; l2 = l2->next;
        }
        while(l1){
            int now = l1->val + pre;
            pre = 0;
            if(now >= 10){
                now = now %10;
                pre = 1;
            }
            ListNode* tmp  = new ListNode(now);
            cur ->next = tmp;
            cur = cur->next;
            
            l1 = l1->next;
        }
        while(l2){
            int now = l2->val + pre;
            pre = 0;
            if(now >= 10){
                now = now %10;
                pre = 1;
            }
            ListNode* tmp  = new ListNode(now);
            cur ->next = tmp;
            cur = cur->next;
            l2 = l2->next;
        }
        if(pre){
            ListNode* tmp  = new ListNode(1);
            cur ->next = tmp;
            cur = cur->next;
        }
        return  ans->next ;
    }
};
```
