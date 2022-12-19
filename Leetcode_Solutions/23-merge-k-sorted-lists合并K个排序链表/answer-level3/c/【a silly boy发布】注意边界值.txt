```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#define MAXSIZE 10000

int cmp(const int *a, const int *b) {
    return *(int *)a - *(int *)b;
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    printf("listsSize: %u\n", listsSize);
    if ((lists == NULL) || (listsSize == 0)) {
        return NULL;
    }

    int aIndex = 0;
    int i;
    int num = 0;
    int *a = (int *)malloc(MAXSIZE * sizeof(int));
    memset(a, 0, MAXSIZE * sizeof(int));
    struct ListNode *tmpLists;
    for (i = 0; i < listsSize; i++) {
        if (lists[i] != NULL) {
            tmpLists = lists[i];
            while (tmpLists != NULL) {
                a[aIndex] = tmpLists->val;
                aIndex++;
                tmpLists = tmpLists->next;
            }
        }
    }
    qsort(a, aIndex, sizeof(a[0]), cmp);

    struct ListNode *returnList = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *returnListCpy = returnList;
    for (i = 0; i < aIndex; i++) {
        returnList->val = a[i];
        if (i == (aIndex - 1)) {
            returnList->next = NULL;
        } else {
            returnList->next = (struct ListNode *)malloc(sizeof(struct ListNode));
            returnList = returnList->next;
        }
    }
    if (aIndex == 0) {
        free(returnList);
        return NULL;
    } else {
        return returnListCpy;
    }
}
```
