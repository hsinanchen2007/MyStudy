### 解题思路
与上一题类似，若不存在环，直接返回NULL，若存在环，记录相遇节点的位置p，由于快指针比慢指针快一倍，
假设慢指针走了n，快指针走了2n，也就是说在相遇点再走n步，仍能回到相遇点，
那么我们记a = head,b = p,那么a和b距离节点p的距离是一致的(b在某种意义上是一致的)
那么就类似于Y形的相交链表，a和b到终点的距离一致，那么a和b一直往前走，总会走到同一个节点，这个节点就是环的入口
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
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head,*fast = head;
        while(fast && fast->next && slow){
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow){
                ListNode *p = head,*q = slow;
                while(p != q){
                    q = q->next;
                    p = p->next;
                }
                return p;
            }
        }
        return NULL;
    }
};
```