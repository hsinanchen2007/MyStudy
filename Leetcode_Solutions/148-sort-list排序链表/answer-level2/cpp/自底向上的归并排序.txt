### 代码

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        int len = listLen(head);
        ListNode dummy(0);
        dummy.next = head;
        ListNode *preSegTail, *nextSegHead;
        ListNode *linkA, *linkB, *linkATail, *linkBTail;
        ListNode *currNode;
        for (int sz = 1; sz < len; sz += sz) {
            preSegTail = &dummy;
            while (preSegTail->next) {
                // find linked list A
                linkA = preSegTail->next;
                linkATail = preSegTail;
                for (int i = 0; i < sz && linkATail->next; i++) {
                    linkATail = linkATail->next;
                }
                // cannot split into two linked list
                if (!linkATail->next)
                    break;
                // find linked list B
                linkB = linkATail->next;
                linkBTail = linkATail;
                for (int i = 0; i < sz && linkBTail->next; i++) {
                    linkBTail = linkBTail->next;
                }
                // sort two linked list
                nextSegHead = linkBTail->next;
                currNode = preSegTail;
                linkATail->next = NULL;
                linkBTail->next = NULL;
                while (linkA && linkB) {
                    if (linkA->val < linkB->val) {
                        currNode->next = linkA;
                        linkA = linkA->next;
                    } else {
                        currNode->next = linkB;
                        linkB = linkB->next;
                    }
                    currNode = currNode->next;
                }
                if (linkA) {
                    currNode->next = linkA;
                    linkATail->next = nextSegHead;
                    preSegTail = linkATail;
                } else {
                    currNode->next = linkB;
                    linkBTail->next = nextSegHead;
                    preSegTail = linkBTail;
                }
            }
        }
        return dummy.next;
    }

    int listLen(ListNode* head) {
        int len = 0;
        ListNode* curr = head;
        while (curr) {
            len++;
            curr = curr->next;
        }
        return len;
    }
};
```