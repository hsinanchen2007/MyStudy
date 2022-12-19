类型链表翻转的写法，但此题可以直接交换结点的值即可。
```
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL||head->next==NULL)return head;
        ListNode *fir=head;
        ListNode *sec=head->next;
        ListNode *thi=sec->next;
        while(1){
            swap(sec->val,fir->val);
            if(thi==NULL||thi->next==NULL)return head;
            fir=thi;
            sec=thi->next;
            thi=thi->next->next;
        }
        return head;
    }
};
```
