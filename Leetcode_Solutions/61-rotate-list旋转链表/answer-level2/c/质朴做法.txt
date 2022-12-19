`/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* rotateRightSub(struct ListNode* head, int k, int len, int* arr)
{
    struct ListNode* cur = head;
    struct ListNode* rst = head;
    struct ListNode* tmp = head;
    int i;
    for(i = 0; i < (len - k); i++) {
        cur = cur->next;
    }

    for(i = (len - k); i < len; i++) {
        rst->val = cur->val;
        cur = cur->next;
        rst = rst->next;
    }
    for(i = k; i < len; i++) {
        // printf("%d\n",arr[i-k]);
        rst->val = arr[i-k];
        rst = rst->next;
    }
    return head;
}

struct ListNode* rotateRight(struct ListNode* head, int k)
{
    if (head == NULL || k == 0) {
        return head;
    }
    int len_list = 0;
    struct ListNode* cur = head;
    struct ListNode* tmp = NULL;
    while(cur) {
        len_list++;
        cur = cur->next;
    }
    int *arr;
    arr = (int *)malloc(sizeof(int) * len_list);
    cur = head;
    int i = 0;
    while(cur) {
        arr[i++] = cur->val;
        cur = cur->next;
    }

    if(k >= len_list) {
        if (k % len_list == 0) {
            return head;
        } else {
            tmp = rotateRightSub(head, (k % len_list), len_list, arr);
        }
    } else {
        tmp = rotateRightSub(head, k, len_list, arr);
    }
    return tmp;
    
}`