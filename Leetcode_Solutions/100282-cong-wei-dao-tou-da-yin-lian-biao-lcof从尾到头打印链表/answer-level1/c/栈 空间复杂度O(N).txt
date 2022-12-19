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


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 #define MAXSIZE 10000
int* reversePrint(struct ListNode* head, int* returnSize){
    int stack[MAXSIZE];
    int idx = 0;
    while(head != NULL){
        stack[idx] = head->val;
        head = head->next;
        idx++;
    }
    int *res = (int *)malloc(sizeof(int) * idx);
    int i = 0;
    idx--;
    while(idx >= 0){
        res[i] = stack[idx];
        i++, idx--;
    }
    *returnSize = i;
    return res;
}
```