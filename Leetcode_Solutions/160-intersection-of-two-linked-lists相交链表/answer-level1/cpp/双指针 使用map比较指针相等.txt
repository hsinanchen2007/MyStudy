使用了C++的 map 利用的思想就是 如何两个指针指向的内存一样 两个指针就相等
没有任何优化 比如可以比较两个链表长度 先用谁算 
```
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
            map<ListNode*, bool>point;
            while (headA != nullptr)
            {
                point[headA] = true;
                headA = headA->next;
            }
            while (headB != nullptr)
            {
                if (point[headB]) return headB;
                point[headB] =true;
                headB = headB->next;
            }

            return nullptr;
        }
    
};
```
