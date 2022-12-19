一开始以为是要把每个节点的原位置记录下来，还专门开了个链表记录下标，晕死。。。
更改后c语言双100%
记录下第一个大于等于x的结点的前驱，然后在之后的遍历中只要遇到小于x的点，就插到这个节点后面，然后更新这个前驱结点，直至遍历结束。
```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* partition(struct ListNode* head, int x){
    struct ListNode* dummyhead = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *curprev = NULL,*cur = NULL,*bighead = NULL,*bigheadprev = NULL;

    if (!head) return NULL;
    int i = 0;
    dummyhead->next = head; 
    cur = dummyhead;
    curprev = dummyhead;
    while (cur) {
        curprev = cur;
        if (!(cur = cur->next)) break;//此时cur已完成遍历
        if (cur->val >= x && bigheadprev == NULL) {
            bigheadprev = curprev;
        }

        if (cur->val < x && bigheadprev != NULL) {
            curprev->next = cur->next;
            cur->next = bigheadprev->next;
            bigheadprev->next = cur;
            bigheadprev = cur;
            cur = curprev;
        }
    }
    
    return dummyhead->next;
}
```
