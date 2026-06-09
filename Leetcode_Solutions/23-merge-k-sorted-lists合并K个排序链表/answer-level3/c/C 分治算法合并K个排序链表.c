### 解题思路
1、lists是个指针数组，每个指针指向一个结构体链表；
2、将lists自行进行拆分，最终拆分到是2个结构体链表进行合并；（对mergeKLists()自身进行递归调用，达到lists拆分的目的）
3、mergeKLists()调到最后是2个链表的合并，此时调用static struct ListNode* mergedTwoLists(struct ListNode *list1, struct ListNode *list2)对2个链表进行简单合并；
4、static struct ListNode* mergedTwoLists(struct ListNode *list1, struct ListNode *list2)，每次取出2个链表中的最小值，list1链表取最小值后剩余的数据当作一个新的链表newList1，另一个链表list2没有动; newList1和list2又重复调用mergedTwoLists()进行合并；

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include <stdio.h>
#include <stdlib.h>

static struct ListNode* mergedTwoLists(struct ListNode *list1, struct ListNode *list2)
{
    struct ListNode *newList;

    if (list1 == NULL) {
        return list2;
    }

    if (list2 == NULL) {
        return list1;
    }

    /* 将list1 list2不断拆分 */
    if (list1->val <= list2->val) {
        newList = list1->next;

        list1->next = mergedTwoLists(newList, list2);
        return list1;
    }

    /* else部分 */
    newList = list2->next;

    list2->next = mergedTwoLists(list1, newList);
    return list2;
}

static struct ListNode* mergeKLists(const struct ListNode** lists, const int listsSize){
    int splitSize;
    struct ListNode    *mergedList;

    if (listsSize == 0) {
        return NULL;
    }

    if (listsSize == 1) {
        return lists[0];
    }

    splitSize = listsSize / 2;

    if (splitSize >= 1) {
        /* 将lists进行拆分 */
        mergedList = mergedTwoLists(mergeKLists(lists, splitSize), mergeKLists(&lists[splitSize], listsSize - splitSize));
    }

    return mergedList;
}

#if 0
int main()
{
    struct ListNode *newList = NULL;
    #if 0
    struct ListNode sample1[] = {1, 4, 5};
    struct ListNode sample2[] = {1, 3, 4};
    struct ListNode sample3[] = {2, 9};
    struct ListNode sample4[] = {3, 5, 7, 8, 9};
    #endif
    struct ListNode *sample1;
    struct ListNode *sample2;
    struct ListNode *sample3;
    struct ListNode *sample4;
    struct ListNode **lists;
    int listsSize;

    sample1 = (struct ListNode *)malloc(sizeof(struct ListNode) * 3);
    for (int loop = 0; loop < 2; loop++) {
        sample1[loop].next = &sample1[loop + 1];
        sample1[loop + 1].next = NULL;
    }
    sample1[0].val = 1;
    sample1[1].val = 4;
    sample1[2].val = 5;

    sample2 = (struct ListNode *)malloc(sizeof(struct ListNode) * 3);
    for (int loop = 0; loop < 2; loop++) {
        sample2[loop].next = &sample2[loop + 1];
        sample2[loop + 1].next = NULL;
    }
    sample2[0].val = 1;
    sample2[1].val = 3;
    sample2[2].val = 4;

    sample3 = (struct ListNode *)malloc(sizeof(struct ListNode) * 2);
    for (int loop = 0; loop < 1; loop++) {
        sample3[loop].next = &sample3[loop + 1];
        sample3[loop + 1].next = NULL;
    }
    sample3[0].val = 2;
    sample3[1].val = 9;

    sample4 = (struct ListNode *)malloc(sizeof(struct ListNode) * 5);
    for (int loop = 0; loop < 4; loop++) {
        sample4[loop].next = &sample4[loop + 1];
        sample4[loop + 1].next = NULL;
    }
    sample4[0].val = 3;
    sample4[1].val = 5;
    sample4[2].val = 7;
    sample4[3].val = 8;
    sample4[4].val = 9;

    listsSize = 4;
    lists = (struct ListNode**)malloc(listsSize * sizeof(struct ListNode*));
    lists[0] = sample1;
    lists[1] = sample2;
    lists[2] = sample3;
    lists[3] = sample4;
        
    newList = mergeKLists(lists, listsSize);

    while (newList != NULL) {
        printf("%d->", newList->val);
        newList = newList->next;
    }

    return 0;
}
#endif

```