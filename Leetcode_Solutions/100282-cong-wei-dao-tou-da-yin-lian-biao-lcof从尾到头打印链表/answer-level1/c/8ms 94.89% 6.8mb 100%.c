### 解题思路

注意要对returnSize赋值  不然会出错

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

#include <string.h>
 typedef struct ListNode ListNode;

int* reversePrint(struct ListNode* head, int* returnSize){
    ListNode *p=head;
    int sum=0;
    while(p!=NULL){
        p=p->next;
        sum++;
    }
    p=head;
    *returnSize=sum;
    int *res=(int*)malloc(sum*sizeof(int));
    memset(res,0,sum*sizeof(int));
    while(p!=NULL){
        res[--sum]=p->val;
        p=p->next;
    }
    return res;
}
```