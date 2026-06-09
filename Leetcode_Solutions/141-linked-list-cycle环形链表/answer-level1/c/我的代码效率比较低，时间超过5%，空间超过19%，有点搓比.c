### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    if (head == NULL) {
        return false;
    }
    
    if (head->next == head) {
        return true;
    }

    struct ListNode *res = head;
    struct ListNode *bak = res;
    head = head->next;
    res->next = NULL;

    while(head != NULL) {
        //printf("head->val = %d, head->next = 0x%x\n", head->val, head->next);
        res = bak;
        while (res->next != NULL) {
            //printf("head = 0x%x, res = 0x%x\n", head, res);
            if (head == res) {
                return true;
            }
            res = res->next;
        }
        //last res
        if (head == res) {
            return true;
        }
        else {
            res->next = head;
        }
        head = head->next;
        if (res->next) {
            res->next->next = NULL;
        }
    }

    return false;
}
```