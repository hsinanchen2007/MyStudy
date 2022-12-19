我开始是这样想的，先遍历两个链表求和，再把得到的和每次对10取余放到链表中，然后再把和值sum/10
代码我放下面了，测试可以过，提交不能过
这样做的问题是我无法给定sum多大的内存空间，链表可以无穷长，而我放总合的sum却不能，本人新手，希望有和我想一样的新手看到的吸取教训
```
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       ListNode* result=new ListNode(0);
        ListNode* res=result;
        int sum=0;
        int k1=1,k2=1;
       while(l1||l2)
        {  
            if(l1!=NULL)
            {
                sum+=(l1->val)*k1;
                l1=l1->next;
                k1=k1*10;
            }
            if(l2!=NULL)
            {
                sum+=(l2->val)*k2;
                l2=l2->next;
                k2=k2*10;
            }
        }
        while(sum>0)
        {
            res->val=sum%10;
            res->next=new ListNode(sum);
            if(sum<10)
                res->next=NULL;
            else
                res=res->next;
            sum=sum/10;      
        }
        return result;
    }
};
```

