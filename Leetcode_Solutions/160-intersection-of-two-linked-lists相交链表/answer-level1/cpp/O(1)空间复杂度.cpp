两个头结点分别遍历一遍，得到各自的长度，计算差值，第二遍两端同时遍历，并按差值调整时距终点更远的头结点起始位置。

```c++
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return nullptr;
        ListNode* tempA = headA;
        ListNode* tempB = headB;
        int lenA = getLen(headA), lenB = getLen(headB);
        int indent_len = lenA - lenB;
        if (indent_len > 0)
            while(indent_len--) tempA = tempA->next;
        else if (indent_len < 0) 
            while(-(indent_len++)) tempB = tempB->next;
        while (tempA && tempB) {
            if (tempA == tempB) return tempA;
            tempA = tempA->next;
            tempB = tempB->next;
        }
        return nullptr;      
    }
    
    int getLen(ListNode* ln) {
        ListNode* temp = ln;
        int len = 0;
        while(temp) {
            ++len;
            temp = temp->next;
        }
        return len;
    }
};
```
