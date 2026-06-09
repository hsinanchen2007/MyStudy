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
struct ListNode* GetMin(struct ListNode** lists, int listsSize) {
    struct ListNode* tmp = NULL;
    int j;
    for (j = 0; j < listsSize; j++) {
        if (lists[j] != NULL) {
            tmp = lists[j];
            break;
        }
    }

    if (j == listsSize) {
        return NULL;
    }

    int i;
    int num = j;
    for (i = j; i < listsSize; i++) {
        if (lists[i] != NULL) {
            if (lists[i]->val < tmp->val) {
                tmp = lists[i];
                num = i;
            }
        }
    }

    lists[num] = lists[num]->next;
    tmp->next = NULL;
    return tmp;
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    struct ListNode *head = GetMin(lists, listsSize);
    struct ListNode *tail = head;
    struct ListNode *tmp;

    while((tmp = GetMin(lists, listsSize)) != NULL) {
        tail->next = tmp;
        tail = tmp;
    }
    
    return head;
}
```