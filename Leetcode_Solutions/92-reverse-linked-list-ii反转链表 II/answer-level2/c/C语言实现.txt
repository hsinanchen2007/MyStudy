![截图.PNG](https://pic.leetcode-cn.com/3e254256055ad1b1e9c91957464e2fa04e1bc0e8372b5a9ee92e09f8ce0f3514-%E6%88%AA%E5%9B%BE.PNG)


### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* reverseBetween(struct ListNode* head, int m, int n){
    if(head == NULL || head->next == NULL || (m == 1 && n == 1) || m == n) {
        return head;
    }
    struct ListNode temp, *p1, *p3, *p4;
    int num = 1;
    temp.next = head;
    head = &temp;
    p1 = head;
    p3 = NULL; printf("%d,%d",m,n);
    while(p1 != NULL) {
        struct ListNode *p2 = p1->next;
        if(num == m && p2 != NULL) {
            p3 = p2;
            p1->next = p2->next;
            p2->next = NULL;
            p4 = p3;
        } else if(num > m && num < n && p2 != NULL) {
            p1->next = p2->next;
            p2->next = p3;
            p3 = p2;
        } else if(num == n) {
            p4->next = p2->next;
            p2->next = p3;
            break;
        } else {
            p1 = p1->next;
        }
        num++;
    }
    return temp.next;
}
```