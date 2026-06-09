如果存在相同节点，那么链表A,B从相同的节点开始到链表结束的距离都是一样的。
因此找出两个链表第一次剩余的长度相同的节点，然后往后遍历判断即可。

具体做法：
因此首先通过O(m+n)的时间计算出A,B链表的长度，然后如果A长，那么A就一直往前走直到走到剩余长度跟B链表长度一样长的那个节点，如果B长也同理。
然后就判断此时A,B节点是否相同，相同则返回，不相同两者同时前进一步直到结束。
```
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int l1 = 0;
        int l2 = 0;
        ListNode *temp = headA;
        // 分别计算A,B链表的长度
        while(temp){
            ++l1;
            temp = temp->next;
        }
        temp = headB;
        while(temp){
            ++l2;
            temp = temp->next;
        }
        // 将两个链表定位到链表剩余长度第一次相同的节点
        while(l1>l2){
            headA = headA->next;
            --l1;
        }
        while(l2>l1){
            headB = headB->next;
            --l2;
        }
        // 判断两个节点是否相同
        while(headA&&headB&&headA!=headB){
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }
};
```
