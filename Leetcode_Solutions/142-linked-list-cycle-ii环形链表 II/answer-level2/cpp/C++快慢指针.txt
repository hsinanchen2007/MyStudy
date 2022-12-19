**1、如何判断一个链表是否存在环？设定两个指针slow，fast，均从头指针开始，每次分别前进1步、2步。如存在环，则两者相遇；如不存在环，fast遇到NULL退出。
2、如果链表存在环，如果找到环的入口点？当fast若与slow相遇时，slow肯定没有走遍历完链表或者恰好遍历一圈。于是我们从链表头与相遇点分别设一个指针，每次各走一步，两个指针必定相遇，且相遇第一点为环入口点。
**

```
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head->next == NULL){
            return NULL;
        }
        ListNode *slow = head, *fast = head;
        //判断是否存在环
        while(fast !=NULL  && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                break;
            }
        }
        if ((fast == NULL) || (fast->next == NULL)) {  //链表不存在环
            return NULL;
        }
        //找到环入口
        slow = head;
        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        } 
        return slow;
    }
};
```
