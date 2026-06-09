### 解题思路
此处撰写解题思路
成环的链表， 同时出发，速度不一样的两个指针总会相遇。 注意处理边界条件，比如列表长度为1的情况。
1. 两个指针都从头开始。
2. 一个指针走两步， 一个指针走一步。 前者要分步走， 确保不会遇到空指针的情况。 
3. 当两个指针相遇， 而且不是在链表尾部（即不为NULL)， 则成环，返回true。
4. 当两个指针中有一个走到了链表尾部（即值为NULL)，则不成环，返回false。

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
    bool hasCycle(ListNode *head) {
        ListNode *p1=head, *p2=head;
        while(p1 && p2) {
            p1 = p1->next;
            p2 = p2->next;
            if (p2) {
                p2 = p2->next;
            };
            if ((p1==p2) && (p1!=NULL))
                return true;
        }
        return false;
        

    }
};
```