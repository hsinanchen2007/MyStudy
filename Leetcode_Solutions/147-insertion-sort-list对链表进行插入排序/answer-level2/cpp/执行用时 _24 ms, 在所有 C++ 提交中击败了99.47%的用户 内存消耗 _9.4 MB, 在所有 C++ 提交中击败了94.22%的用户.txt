```
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        auto dummy = ListNode(-1);
        ListNode* tail = nullptr;//增加tail
        while(head){
            auto* cur = &dummy;
            //判断是否比排序后最右边的值大,由此来减少比较次数
            if(tail && tail->val < head->val)
                cur = tail;
            else
                while(cur->next && cur->next->val < head->val) 
                    cur=cur->next;
            auto* tmp=head;
            head=head->next;
            
            if(!cur->next) tail = tmp;//如果是插入到最右边,说明tmp是最大值
            tmp->next=cur->next;
            cur->next=tmp;
        }
        return dummy.next;
    }
};
```
