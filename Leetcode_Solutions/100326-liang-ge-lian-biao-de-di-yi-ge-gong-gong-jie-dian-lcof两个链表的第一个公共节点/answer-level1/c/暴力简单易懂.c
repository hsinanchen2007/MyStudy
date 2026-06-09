```
int getListLen(struct ListNode *head)
{
    int len = 0;
    
    while (head != NULL) {
        len++;
        head = head->next;
    }

    return len;
}

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) 
{
    int lenA;
    int lenB;

    if ((headA == NULL) || (headB == NULL)) {
        return NULL;
    }

    lenA = getListLen(headA);
    lenB = getListLen(headB);

    if (lenA > lenB) {
        // A先走
        for (int i = 0; i < lenA - lenB; i++) {
            headA = headA->next;
        }
    } else {
        // B先走
        for (int i = 0; i < lenB - lenA; i++) {
            headB = headB->next;
        }
    }

    while ((headA != NULL) && (headB != NULL)) {
        if (headA == headB) {
            return headA;
        }

        headA = headA->next;
        headB = headB->next;
    }

    return NULL;
}
```
