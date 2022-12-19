### 解题思路
将两个链表连接遍历，A+B=B+A

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
        ListNode* l1=headA;
        ListNode* l2=headB;
        //l1=l2表示遍历结束，如果是相交链表，一定会同时指向相交的节点,
        //如果不相交，最终l1和l2都会同时指向末尾null
        //遍历长度都是整个A+B
        while(l1!=l2){
            l1=(l1==NULL)?headB:l1->next;
            l2=(l2==NULL)?headA:l2->next;
        }
        return l1;
    }
};
```