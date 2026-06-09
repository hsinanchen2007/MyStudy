### 解题思路
学习小结：
使用dummuyhead避免在代码中判断头结点，简化操作，最后有效的头结点是dummyhead的后一个。

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* cur1 = l1;
    struct ListNode* cur2 = l2;
    int val1,val2,val;
    //carry表示进位的值，0或1
    int carry = 0;
    //dummyhead的作用是避免在代码的执行中判断是否为头结点，简化代码。
    struct ListNode*dummyhead = (struct ListNode*)malloc(sizeof(struct ListNode)); 
    //cur当前结点的作用是记录链表最新的结点。
    struct ListNode*cur=dummyhead;
    //两个链表有一个不为空都需要继续，carry等于1是考虑最后需要进位的情况
    while(cur1!=NULL|cur2!=NULL|carry==1)  
    {
        //当链表为空时值为0
        if(cur1!=NULL)
        {
            val1=cur1->val;
            cur1=cur1->next;
        }
        else
        {
            val1=0;
        }

        if(cur2!=NULL)
        {
            val2=cur2->val;
            cur2=cur2->next;
        }
        else
        {
            val2=0;
        }

        val=(val1+val2+carry) % 10;
        carry=(val1+val2+carry)>=10 ? 1:0;
        cur->next=(struct ListNode*)malloc(sizeof(struct ListNode));
        cur->next->val=val;
        cur->next->next=NULL;
        cur=cur->next;
    }      
    //实际有效的链表头为dummhead的下一个
    return dummyhead->next;              
}


```