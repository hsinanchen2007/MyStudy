模拟加法的过程，
用一个变量来保存进位。
特殊处理：当l1或者l2的末尾没有元素的时候 ，补0，从而在循环退出之后不用进一步处理剩余元素。```
代码块
```
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      ListNode *pre=new ListNode(0);
      ListNode *cur=pre;
      int carry=0;
      while(l1!=nullptr||l2!=nullptr)
      {
          int x=l1==nullptr?0:l1->val;//特殊处理
          int y=l2==nullptr?0:l2->val;

          int temp=x+y+carry;

          int sum=temp%10;
          carry=temp/10;

          cur->next=new ListNode(sum);
          cur=cur->next;

          if(l1!=nullptr)
          l1=l1->next;
          if(l2!=nullptr)
          l2=l2->next;

          

      } 
       if(carry)
       {
           cur->next=new ListNode(carry);
       }
       return pre->next;

    }
};
```


