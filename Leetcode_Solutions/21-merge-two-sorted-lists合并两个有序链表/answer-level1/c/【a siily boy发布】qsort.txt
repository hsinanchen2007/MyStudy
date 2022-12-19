```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode ListNode;
#define MAXSIZE 1001

int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    if (l1 == NULL) {
		return l2;
    }
	if (l2 == NULL) {
		return l1;
    }

    int i;
	int cnt = 0;
    int *returnArray = (int *)malloc(MAXSIZE * sizeof(int));
    ListNode* l1Tmp = l1;
    ListNode* l2Tmp = l2;

    while(l1Tmp != NULL) {
        returnArray[cnt] = l1Tmp->val;
        cnt++;
        l1Tmp = l1Tmp->next;
    }
    while (l2Tmp != NULL) {
        returnArray[cnt] = l2Tmp->val;
        cnt++;
        l2Tmp = l2Tmp->next;   
    }

    qsort(returnArray, cnt, sizeof(returnArray[0]), cmp);
    //printf("returnArray[0]: %u\n", returnArray[0]);

    ListNode *returnList = (ListNode *)malloc(sizeof(ListNode));
    ListNode *returnListCpy = returnList;
    for (i = 0; i < cnt; i++) {
        returnList->val = returnArray[i];
        //printf("returnArray[%u]: %u\n", i, returnArray[i]);
        if (i == cnt - 1) {
            returnList->next = NULL;
        } else {
            returnList->next = (ListNode *)malloc(sizeof(ListNode));
            returnList = returnList->next;
        }
    }

    return returnListCpy;

}
```
