### 解题思路
l1，l2同时遍历相加，并将结果返回到l1。
如果两者同时达到链表尾，结束。
如果其中一个到达链表尾，而另一条未到达，则转到较长的链表上继续进行，遍历至链表结束。
返回l1的链表头。

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode* p1= l1;         //记录返回链表的开头   
    struct ListNode* newtail = (struct ListNode*) calloc (1, sizeof(struct ListNode));  //最高位有进位时要添加的节点
    newtail->val=1;
    newtail->next=NULL;
    int carry=0;                     //初始化进位标志
    
    while(l1&&l2)                            //将l2链上的数据加至l1       
    {
        l1->val = l1->val + l2->val + carry;        //处理进位
        if(l1->val>=10) 
        {
            l1->val=l1->val%10;
            carry=1;
        }
        else carry=0;

        if((l1->next==NULL)||(l2->next==NULL))    //如果其中一个的next为空
        {
            if((l1->next==NULL)&&(l2->next==NULL))  //如果l1,l2同时到达链表尾
            {
                if(carry) l1->next= newtail;           //如果进位，加入最高位
                return p1;
            }

            if(l2->next!=NULL&&l1->next==NULL)    //如果l2的next不为空,而l1的next为空,将l1的链表接到l2上  
            l1->next=l2->next;     
                          
            l1=l1->next;        //l1指向l1->next
            break;              //跳出循环，进入下一轮
        }
        l1=l1->next;
        l2=l2->next;
    }

    while(l1)                   //此时只剩下一条链l1
        {
            if(carry) l1->val = l1->val + 1;        //处理进位
            if(l1->val>=10)                 
            {
                carry=1; 
                l1->val=l1->val%10; 
            }   
            else carry=0;

            if(l1->next==NULL)              //到达链表尾部
            {
                if(carry) l1->next= newtail;  //如果进位，加入最高位
                return p1;
            }
            l1=l1->next;
        }
    return NULL;
}
```