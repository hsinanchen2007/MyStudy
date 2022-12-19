C++实现

A: 1-2-3-8-9
B: 5-3-8-9

AB: 1-2-3-8-9-5-3-8-9
BA: 5-3-8-9-1-2-3-8-9

从上面的AB和BA一直找到相同的第一个值(3)为止


```
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr) return nullptr;

        ListNode* preA = headA;
        ListNode* preB = headB;

        while(preA != preB) {  // null == null
            preA = (preA == nullptr) ? headA : preA->next;
            preB = (preB == nullptr) ? headB : preB->next;
        }


        return preA;
    }
```
