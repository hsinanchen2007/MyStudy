思想很简单 可以先做完206的反转链表再来做，这里每k个为翻转循环，每次翻转k个，一旦链表不满足k个之后直接返回。在这里是单独写了一个翻转函数进行。
![image.png](https://pic.leetcode-cn.com/8cc76e690388e96b3212bcd01fb1d8cb275f4ef91a98e277dff3d4dcda7a6e49-image.png)

```
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k==1) return head;
        ListNode* newHead=new ListNode(-1);
        ListNode* tt=newHead;
        tt->next=head;
        ListNode* pos=head;
        while(pos!=NULL){
            ListNode *first=pos;
            //每次找到要反转的最后一个位置
            for(int i=1;i<k;i++){
                pos=pos->next;
                if(pos==NULL) return newHead->next;
            }
            ListNode* second=pos->next;
            ListNode * temp=reverse(first,pos);
            first->next=second;
            tt->next=temp;
            tt=first;
            pos=second;   
        }
        return newHead->next;
    }
    
    // 递归先进行反转
    ListNode* reverse(ListNode* head,ListNode* pos){
        if(head==pos->next || head->next==pos->next) return head;
        ListNode* res=reverse(head->next,pos);
        head->next->next=head;
        head->next=NULL;
        return res;
    }
};
```
