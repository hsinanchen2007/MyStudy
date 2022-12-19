### 解题思路
此处撰写解题思路

### 代码

```c
#include <string.h>

int* reversePrint(struct ListNode* head, int* returnSize){

    struct ListNode *pNode=head;
    int cnt=0;
    while(pNode != NULL){
        pNode = pNode->next;
        cnt++;
    }
    pNode = head;
    *returnSize=cnt;
    int *res=(int*)malloc(cnt*sizeof(int));
    memset(res,0,cnt*sizeof(int));
    while(pNode != NULL){
        res[--cnt] = pNode->val;
        pNode = pNode->next;
    }
    return res;
}

```