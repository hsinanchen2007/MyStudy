思路：这道题关键在于数字在链表中是逆序存储，而数字相加正好是从低位到高位逆序相加的。所以最后考虑到进位就链表顺序对应位相加


```
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       
        ListNode* head=new ListNode(-1);//头节点
        ListNode* curr=head;//游标

        int sum=0;
        int carry=0;//进位标志

        while(l1!=NULL||l2!=NULL)
        {
            sum=0;         //最开始要清零
            if(l1!=NULL)
            {
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2!=NULL)
            {
                sum+=l2->val;
                l2=l2->next;
            }
            if(carry==1)
            {
                sum++;
            }

            carry=sum/10;
            ListNode* temp=new ListNode(sum%10);
            curr->next=temp;
            curr=temp;

        }

        if(carry==1)//最后要判断进位
        {
            curr->next=new ListNode(1);
        }
        return head->next;
    }
};
```
