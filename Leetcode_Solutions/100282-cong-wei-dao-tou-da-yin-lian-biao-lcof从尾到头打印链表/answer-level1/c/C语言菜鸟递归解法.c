

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

void print(struct ListNode* head,int* returnNums,int* returnSize)
{
    if(head->next!=NULL)
    {
        print(head->next,returnNums,returnSize);
    }
    returnNums[*returnSize] = head->val;
    *returnSize = *returnSize + 1;
}



int* reversePrint(struct ListNode* head, int* returnSize){
    if(head == NULL)
    {
        *returnSize = 0;
        return NULL;
    }
    int* returnNums = (int*)malloc(sizeof(int)*10000);
    *returnSize = 0;
    print(head,returnNums,returnSize);
    return returnNums;
}
```