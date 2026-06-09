三个指针，pre,cur,nex,先把cur的下一个指pre，然后pre指向cur，cur指向nex，nex指向下一个next；
```
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head)return head;
        ListNode* pre=nullptr;ListNode*cur=head;ListNode*nex=head->next;
        while(cur){
            cur->next=pre;
            pre=cur;
            cur=nex;
            if(cur)nex=cur->next;//防止cur为null
        }
        return pre;
    }
};
```
代码超简洁