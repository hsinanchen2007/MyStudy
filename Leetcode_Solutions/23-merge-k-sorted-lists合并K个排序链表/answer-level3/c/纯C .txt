### 解题思路
brute force
### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode LNode, *LinkList;

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    if (listsSize == 0) 
    {
        return NULL;
    }

    if (listsSize == 1) 
    {
        return lists[0];
    }

    //dummy node
    LNode dummyNode;
    dummyNode.next = NULL;

    // new list
    LinkList pPre = &dummyNode;
    LinkList pCur;

    // to find the min
    int min = INT_MAX;
    int indexOfList = 0;
    int indexOfMinHeadNode = 0;

    while(indexOfList != -1) // will close until lists be null
    {
        min = INT_MAX; // update min to max
        indexOfList = -1; // close

        for(indexOfMinHeadNode = 0; indexOfMinHeadNode <= listsSize - 1; indexOfMinHeadNode++) 
        {
            if(lists[indexOfMinHeadNode] != NULL && lists[indexOfMinHeadNode]->val < min) 
            {
                min = lists[indexOfMinHeadNode]->val;
                indexOfList = indexOfMinHeadNode; // update index, open
            }
        }

        if(indexOfList != -1) 
        {
            pCur = (LinkList)malloc(sizeof(*pCur));
            pCur->val = min;
            pCur->next = NULL;

            pPre->next = pCur;
            pPre = pCur;

            lists[indexOfList] = lists[indexOfList]->next;
        }
    }

    return dummyNode.next;
}
```