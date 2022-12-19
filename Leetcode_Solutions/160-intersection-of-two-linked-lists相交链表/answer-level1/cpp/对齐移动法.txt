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
        int Length_A = ListNode_len(headA);
        int Length_B = ListNode_len(headB);
        if(Length_A>Length_B)
        {
            headA = return_short_head(headA, headB, headA);  //如果A链表长，移动A链表
        }
        else
        {
            headB = return_short_head(headB, headA, headB);
        }
        while(headA&&headB)
        {
            if(headA==headB)
            {
                return headA;
            }
            headA = headA->next;
            headB = headB->next;
        }
        return NULL;
    }
    int ListNode_len(ListNode *head)
    {
        int Length=0;
        while(head)
        {
            Length++;
            head=head->next; //遍历节点
        }
        return Length;
    }

    ListNode *return_short_head(ListNode *long_head, ListNode *short_head, ListNode *head)
    {
        int count=ListNode_len(long_head) - ListNode_len(short_head);
        while(count&&head)
        {
            head=head->next;  //将指针向后移动到相等的位置
            count--;
        }
        return head;
    } 
};
```