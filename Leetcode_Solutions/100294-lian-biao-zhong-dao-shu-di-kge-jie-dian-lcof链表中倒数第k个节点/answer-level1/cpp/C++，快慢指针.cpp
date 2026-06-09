快慢指针应用，快指针先走k-1步，再让快慢指针一起动，这样可以保持快慢指针之间始终有k-1个节点。当快指针到达尾节点时，慢指针的位置就是需要的节点位置。
但要注意三点：
1. 链表为空
2. k<=0
3. k大于链表长度
```
class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {

        if(head==nullptr||k<1) return nullptr;

        ListNode* fast=head;
        ListNode* slow=head;

        //让fast指针先走k-1步
        for(int i=1;i<=k-1;i++){
            //防止k大于链表的长度
            if(fast->next!=nullptr){
                fast=fast->next;
            }
            else{
                return nullptr;
            }   
        }

        while(fast->next!=nullptr){
            fast=fast->next;
            slow=slow->next;
        } 

        return slow;
    }
};
```
