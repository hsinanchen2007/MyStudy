```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#define MAXSIZE 100001

struct ListNode *a[MAXSIZE];

bool isExit(int count, struct ListNode *head) {
    int i;
    for (i = 0; i < count; i++) {
        if (a[i] == head) {
            return true;
        }
    }

    return false;
}

bool hasCycle(struct ListNode *head) {
    if (head == NULL) {
        return false;
    }

    int count = 0;
    bool returnValue;
    while(head != NULL) {
        a[count] = head;
        count++;
        head = head->next;
        returnValue = isExit(count, head);
        if (returnValue == true) {
            return true;
        }
    }

    return false;
}
```
