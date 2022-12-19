### 解题思路

1. 设头-环头距离为$a$,环长为$b$且链表长度$L=a+b$
2. 一轮相遇时由$f=2s; f=s+nb;$推导得出$s=nb$.
3. 二轮令慢指针再走a步即可到达环头
4. 一次相遇后令fast指向head并以步调为1行走，二者会在环头处再次相遇。
5. 特殊情况：若$a=0$时则$b=L$,即head=环头,则第一次相遇必在head处。

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
        ListNode *slow=head, *quick=head;
        int same = 0;
        while(quick != NULL && quick->next !=NULL && quick->next->next!=NULL){
            slow = slow->next;
            quick = same==0 ? quick->next->next : quick->next;
            if(slow == quick) {
                // 一般情况一轮f = 2s = 2nb, 2轮在环头相遇。
                // 特殊情况，当a=0时，1轮一定会在头部相遇，环头=head。
                if(slow == head) return slow;
                else if(same == 0) {quick = head; same++;}
                else return slow;
            }
        }
        return NULL;
    }
};
```