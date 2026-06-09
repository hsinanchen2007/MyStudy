![F22647D8-A640-45F9-826B-A239D7E4B8E4.jpeg](https://pic.leetcode-cn.com/51f5d70a4718c145df42917570581336ec02968d755a4435d737166a57a6876c-F22647D8-A640-45F9-826B-A239D7E4B8E4.jpeg)

```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
//拼接链表

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
    if (l1 == NULL) {
        return l2;
    }
    if (l2 == NULL) {
        return l1;
    }


    struct ListNode *returnList = (struct ListNode *)malloc(sizeof(struct ListNode));
    returnList->val = -1;
    returnList->next = NULL;
    struct ListNode *returnRecordList = returnList;

    bool isFirst = false;
    while ((l1 != NULL) && (l2 != NULL)) {
        if (l1->val < l2->val) {
            returnList->next = l1;
            l1 = l1->next;
        } else {
            returnList->next = l2;
            l2 = l2->next;
        }
        //printf("returnList->val: %d\n", returnList->val);
        returnList = returnList->next;
    }

    if (l1 != NULL) {
        returnList->next = l1;
    }
    if (l2 != NULL) {
        returnList->next = l2;
    }
    returnRecordList = returnRecordList->next;
    return returnRecordList;
}
```
