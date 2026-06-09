废话不说，先上代码。
```
class Solution {
public:
    //获取链表长度
    int getLenOfList(ListNode* head)
    {
        int i = 0;
        while(head)
        {
            i++;
            head = head->next;
        }

        return i;
    }

    //翻转链表
    ListNode* reverseList(ListNode* head)
    {
        ListNode* new_head = NULL;
        while(head)
        {
            ListNode* tmp = head->next;
            head->next = new_head;
            new_head = head;
            head = tmp;
        }

        return new_head;
    }
    //这个函数功能不太直观，需要仔细看看
    //具体来说就是分割链表，将前k个节点作为第一部分
    //后面所有的代码作为第二部分
    //并且返回指向第k+1结点的指针
    ListNode* cut(ListNode* head,int k)
    {
        ListNode* pre_head = head;
        while(pre_head && --k)
        {
            pre_head = pre_head->next;
        }

        if(!pre_head) return NULL;

        ListNode* next = pre_head->next;
        pre_head->next = NULL;

        return next;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        //伪头结点
        ListNode dummy(0);
        ListNode* ptr = &dummy;
        //获取分组数
        int cnt = getLenOfList(head)/k;
        
        //cut()将链表分为左右两部分
        //left,right分别为左右两部分的头指针
        ListNode* left = head;
        ListNode* right = cut(head,k);

        while(cnt--)
        {
            //此时left仍然是翻转前的头结点
            //反转函数返回的是每个小组新的头结点
            ptr->next = reverseList(left);

            //将ptr指向新链表的最后一个结点
            while(ptr->next)
            {
                ptr = ptr->next;
            }

            //完成一个小组的翻转，进行下一组翻转
            left = right;
            right = cut(left,k);
        } 

        //将最后剩余的不够k个的节点也连接到链上
        if(left) ptr->next = left;

        return dummy.next;   
    }
};
```
本人解这道题时思路很简单，就是计算需要进行多少组，然后分组（即使用cut切割链表），紧接着按组翻转每组链表，再链接到一块儿。
使用的方法有(1)getLenOfList() (2)reverseList()翻转每组链表 （3）cut()切割链表

感觉链表题比较有套路,经常使用的方法有（1）快慢指针 （2）mergeSortedList() (3)reverseList() (4)cut (5)getLenOfList(),有时候为了解题方便
还会用到伪头结点的方法。然后解题时，将问题分割成子问题，再用以上几个方法来解决就好。上面已经给出了后面三个的代码，接下来给出mergeSortedList()的代码实现。。
```
    ListNode* mergeSortedList(ListNode* l1,ListNode* l2)
    {
        ListNode dummy(0);
        ListNode* ptr = &dummy;
        
        while(l1 && l2)
        {
            if(l1->val < l2->val){
                ptr->next = l1;
                ptr = l1;
                l1 = l1->next;
            }
            else{
                ptr->next = l2;
                ptr = l2;
                l2 = l2->next;
            }
        }
        
        ptr->next = (l1 == NULL)? l2:l1;
        
        return dummy.next;
    }
```

