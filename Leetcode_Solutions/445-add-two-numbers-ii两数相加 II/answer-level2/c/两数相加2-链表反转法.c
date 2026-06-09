```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode* node;

node reverse(node head)
{
    if (head == NULL) return head;
    node pre = NULL;
    node cur = head;
    node ne = cur->next;
    while (cur != NULL) {
        cur->next = pre;
        pre = cur;
        cur = ne;
        if (ne != NULL) ne = ne->next;   
    }
    return pre;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    if (l1 == NULL) return l2;
    if (l2 == NULL) return l1;
    node rvsHead1;
    node rvsHead2;
    node res = NULL;
    rvsHead1 = reverse(l1);
    rvsHead2 = reverse(l2);
    int t = 0;
    while (rvsHead1 != NULL || rvsHead2 != NULL || t) {
        if (rvsHead1 != NULL) {
            t += rvsHead1->val;
            rvsHead1 = rvsHead1->next;
        }
        if (rvsHead2 != NULL) {
            t += rvsHead2->val;
            rvsHead2 = rvsHead2->next;
        } 
        node temp = (node) malloc(sizeof(struct ListNode));
        temp->next = NULL;
        temp->val = t % 10;
        if (res == NULL) res = temp;
        else {
            temp->next = res;
            res = temp;
        }
        t /= 10;
    }
    return res;
}
```
