###
快慢指针：快指针到达尾部时，慢指针指向所需删除节点的前一个指针
由于此处为不带头结点的链表，慢指针指向被删除指针会更好。因为当被删除节点应为头结点时，慢指针无法指向它的前一个指针，此处为了解决这个问题添加判断：slow==head&&n>0。
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *fast=head,*slow=head,*p;
        while(fast->next!=NULL){
            fast=fast->next;
            if(n>0){
                n--;
            }else{
                slow=slow->next;
            }
        }
        if(slow==head&&n>0){
            head=slow->next;
            delete slow;
        }else{
            p=slow->next;
            slow->next=p->next;
            delete p;
        }

        return head;
        
    }
};
```