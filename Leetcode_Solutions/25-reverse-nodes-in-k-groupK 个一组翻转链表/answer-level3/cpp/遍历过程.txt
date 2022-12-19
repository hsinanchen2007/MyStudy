以12345，k=3为例
这里依旧引入伪头结点dummy->1->2->3->4->5
start指向dummy，mid指向1，tail指向2
len分为三种状态：
0--根据mid和tail不空，len=2
k--可以把(mid,tail]都塞到start之后，从而达到链表逆转的操作（此操作分为从后面删除和从前面插入两步）
其他--继续收集符合条件的结点数目，不足k时不操作

最后补一次操作，防止因为len!=0且len!=k的时候len++很可能满足k且tail到达了链表末尾，那么退出了循环，此时应该补上一次链表逆转操作

```
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(-1);
        dummy.next=head;
        ListNode* start=&dummy;
        if(!head || !head->next)
            return head;
        if(k<2)
            return head;
        ListNode* mid=head;
        ListNode* tail=head->next;
        int len=0;
        while(mid&&tail)     
        {
            if(len==0)
            {
                len=2;
                tail=tail->next;
            }
            else if(len==k)
            {//把(mid,tail]都塞进[start,mid]里面去
                for(size_t i=1;i<k;i++)
                {
                    ListNode* tmp=mid->next;
                    mid->next=tmp->next;
                    tmp->next=start->next;
                    start->next=tmp;
                }
                len=0;
                start=mid;
                mid=start->next;
                if(mid)
                    tail=mid->next;
                else
                    break;
            }
            else
            {
                len++;
                tail=tail->next;
            }
        }
        //之所以再判断一次是因为len!=0且len!=k的时候len++很可能满足k且tail到达了链表末尾，那么退出了循环，此时应该补上一次链表逆转操作
        if(len==k)
        {//把(mid,tail]都塞进[start,mid]里面去
            for(size_t i=1;i<k;i++)
            {
                ListNode* tmp=mid->next;
                mid->next=tmp->next;
                tmp->next=start->next;
                start->next=tmp;
            }
        }
        return dummy.next;
        
    }
};
```
