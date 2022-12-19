### **解题思路**
用一个int来存，左边链表还有的话就加进来，右边同理，进位判断有的话也加进来，加完后判断是否需要进位，并把个位数存入新开的链表里。/左右两边链表都没了的话就结束。
![image.png](https://pic.leetcode-cn.com/408a125a3feae9749a45e26852367151c9fc887c976cae7ffb1f7d2bdc1a4e27-image.png)
或许可以为了省空间而把值存入左右链表的任意一个，但我懒了。。。

### **代码**
```
class Solution 
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        bool flag=false;    //进位判断
        bool f=true;        //创建链表的判断，判断第一次，创建链表头
        bool LL=true;       //第一个数字是否用尽判断
        bool RR=true;       //第二个数字是否用尽判断
        
        ListNode *head = NULL;
        ListNode *p = NULL;
        
        while(LL || RR)
        {
            int temp=0;     //中间运算
            //前一位有进位时加一
            if(flag)
            {
                temp++;
                flag=false;
            }
            //左右两数分别加到中间运算
            if(LL)
            {
                temp+=l1->val;
                if(l1->next!=NULL)l1=l1->next;
                else LL=false;
            }
            if(RR)
            {
                temp+=l2->val;
                if(l2->next!=NULL)l2=l2->next;
                else RR = false;
            }

            //判断是否需要进位
            if(temp>=10)flag=true;
            temp = temp%10;

            //写入链表部分
            if(f)
            {
                head = new ListNode(temp);
                p = head;
                f=false;
            }
            else 
            {
                ListNode *q =  new ListNode(temp);
                p->next = q;
                p = q; 
            }

        }
        
        //如果最后一位还需要进位的话，额外的操作
        if(flag)
        {
            ListNode *q =  new ListNode(1);
            p->next = q;
        }
        return head;
    }
};

```




