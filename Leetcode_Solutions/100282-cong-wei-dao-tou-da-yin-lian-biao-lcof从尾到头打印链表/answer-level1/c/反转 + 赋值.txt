```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* reversePrint(struct ListNode* head, int* returnSize){
    if (head == NULL) {
        *returnSize = 0;
        return NULL;
    }
    struct ListNode* cur = NULL;
    struct ListNode* p = NULL;
    int count = 0;
    while (head) {
        p = head;
        head = head->next;
        p->next = cur;
        cur = p;
        count++;
    }
    *returnSize = count;
    int* arr = (int*)malloc(sizeof(int) * count);
    int i = 0;
    while (cur) {
        arr[i++] = cur->val;
        cur = cur->next;
    }

    return arr;

}
```
