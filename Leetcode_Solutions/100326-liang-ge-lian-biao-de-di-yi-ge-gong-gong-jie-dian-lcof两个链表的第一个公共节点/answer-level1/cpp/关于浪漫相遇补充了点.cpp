### 解题思路
此处撰写解题思路

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* noteA;
        ListNode* noteB;
        if(headB==NULL||headA==NULL)return NULL;
        noteA=headA;noteB=headB;
        int flag=0;
        while(noteA!=noteB)
        {
            if(flag>=2)return NULL;
            if(noteB->next!=NULL)
                noteB=noteB->next;
            else 
            {
                noteB=headA;
                flag++;
            }
            if(noteA->next!=NULL)
                noteA=noteA->next;
            else noteA=headB;
        }

        return noteA;
    }
};
```