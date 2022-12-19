##分的比较细 解法比较费劲

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
    int i = 1;
    struct ListNode* p1 = head;
    struct ListNode* p2 = head;
    struct ListNode* p3 = head;
    struct ListNode* pNext = head;
    struct ListNode* pPre = head;

    if(m == n)
        return head;
    if(head == NULL) 
        return head;
    else if(head->next == NULL) 
        return head;
    else if(head->next->next == NULL) {
        head->next->next = head;
        p1 = head->next;
        head->next = NULL;
        
        return p1;
    }


    if(m == 1) {
        p3 = p2->next;
        pPre = p2;
        while(i<=n-1) {
            pNext = p3->next;
            p3->next = p2;
            p2 = p3;
            p3 = pNext;
            i++;
        }
        pPre->next = p3;
        return p2;
    } else {
        while(i<=n) {
            while(i <= m ) {
                if(i >= 3)
                    p1 = p1->next;
                i++;
            }
            if(i == m+1) {
                p2 = p1->next;
                p3 = p2->next;
                pPre = p2;
            }
            pNext = p3->next;
            p3->next = p2;
            p2 = p3;
            p3 = pNext;
            i++;
        }
        p1->next = p2;
        pPre->next = p3;
        return head;
    }
}
```