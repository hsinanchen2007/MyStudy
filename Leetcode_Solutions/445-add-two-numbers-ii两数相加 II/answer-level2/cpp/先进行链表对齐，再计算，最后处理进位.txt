按照要求，不对链表进行修改。
执行用时 : 24 ms, 在Add Two Numbers II的C++提交中击败了100.00% 的用户

内存消耗 : 10.6 MB, 在Add Two Numbers II的C++提交中击败了94.44% 的用户
```
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1&&!l2)
            return NULL;
        else{
            if(!l1)
                return l2;
            if(!l2)
                return l1;
        }
        auto cur1=l1,cur2=l2;
        auto tmphead=new ListNode(0);
        auto rescur=tmphead;
        auto reshead=new ListNode(0);
        auto cur=reshead;
        //将两个链表进行对齐
        while(1){
            if(!cur1||!cur2)
                break;
            else{
                cur1=cur1->next;
                cur2=cur2->next;
            }
        }
        if(!cur1&&cur2){
            while(cur2){
                rescur->next=new ListNode(0);
                rescur=rescur->next;
                cur2=cur2->next;
            }
            rescur->next=l1;
            cur1=tmphead->next;
            cur2=l2;
        }else if(cur1&&!cur2){
            while(cur1){
                rescur->next=new ListNode(0);
                rescur=rescur->next;
                cur1=cur1->next;
            }
            rescur->next=l2;
            cur2=tmphead->next;
            cur1=l1;
        }else{
            cur1=l1;
            cur2=l2;
        }
        //开始计算，先不管进位
        while(cur1){
            
            int val=cur1->val+cur2->val;
            cur->next=new ListNode(val);  
            cur=cur->next;
            
            cur1=cur1->next;
            cur2=cur2->next;
        }
        //保存进位数值
        int c=0;
        //从尾到头，依次处理进位（即cur->val>=10）
        while(cur!=reshead){
            cur->val+=c;
            if(cur->val>=10){
                c=cur->val/10;
                cur->val=cur->val-cur->val/10*10;
            }else
                c=0;
            auto start=reshead;
            //得到前序指针，即cur=cur->prev;
            while(start->next!=cur)
                start=start->next;
            cur=start;
            
        }
        //头结点是否有进位
        if(c==1)
            reshead->val=1;
        
        return reshead->val==1?reshead:reshead->next;
    }
};
```