- 执行用时 :12 ms, 在所有 C++ 提交中击败了90.97%的用户
- 内存消耗 :8.9 MB, 在所有 C++ 提交中击败了81.59%的用户
```
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || k==0)
            return head;
        ListNode *q=head;
        int len=1;
        while(q->next){
            len++;
            q=q->next;//q为最后一个节点
        }
        ListNode *p=q;
        q->next=head;//结环
        for(int i=0;i<len-k%len;i++)
            p=p->next;
        head=p->next;
        p->next=NULL;//断开
        return head;
    }
};
```