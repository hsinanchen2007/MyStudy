### 解题思路
此处撰写解题思路
做这题的时候，我首先想到的是归并排序，但是归并排序的常规思路好像不符合要求。所以我先写了暴力法
首先这个题最容易想到的方法就是插入排序的思路，搞一个结点p和p的后继结点r(后继结点是为了让链表不断链，在链表这类题中非常常见。)然后开始遍历原来的链表，每碰到一个新的结点就把它插入到要排序的那个链表里面。
可能新节点的val很大以至于新节点只能放到最后一个，还有可能新节点的val适中，能够插入到要排序的链表当中来，所以我在这里设置了一个flag，如果能插入到要排序的链表中间就flag=true,后面再处理一下flag.
en,大概学过数据结构的插入排序的人都能很快看懂这个代码。
方法二就是归并排序,权当复习一次了 mark一下
### 代码
//暴力法：
```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
       ListNode *p=head;
       ListNode *r=head;
       ListNode *dummy=new ListNode(0);
       bool flag=false;
       while(p!=NULL)
       {
           r=p->next;//保证链表不断链
           ListNode* insert_node=dummy->next;
           ListNode* pre_node=dummy;
           while(insert_node!=NULL)
           {
               if(p->val<insert_node->val)
               {
                   pre_node->next=p;
                   p->next=insert_node;
                   flag=true;
                   break;
               }
               pre_node=insert_node;
              insert_node=insert_node->next;
           }
           if(flag==false)
           {
               pre_node->next=p;
               p->next=NULL;
           }
           else
               flag=false;
           p=r;
       }
        return dummy->next;
    }
};


//归并排序法
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    //二路归并算法 就是把两个有序链表归并
    ListNode* merge(ListNode* l1,ListNode* l2)
    {
        ListNode* dummy=new ListNode(0);
        ListNode* p=dummy;
        while(l1!=NULL&&l2!=NULL)
        {
            if(l1->val>l2->val)
            {
                p->next=l2;
                l2=l2->next;
                p=p->next;
            }
            else if(l1->val<l2->val)
            {
                p->next=l1;
                l1=l1->next;
                p=p->next;
            }
            else
            {
                p->next=l1;
                l1=l1->next;
                p=p->next;
            }
        }
        while(l1!=NULL)
        {
            p->next=l1;
            l1=l1->next;
            p=p->next;
        }
        while(l2!=NULL)
        {
            p->next=l2;
            l2=l2->next;
            p=p->next;
        }
        return dummy->next;
    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL||head->next==NULL)
        {
            return head;
        }
        ListNode* fast=head;
        ListNode* slow=head;
        ListNode* pre_slow;
        while(fast!=NULL&&fast->next!=NULL)
        {
            pre_slow=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        pre_slow->next=NULL;
        ListNode* l1=sortList(head);
        ListNode* l2=sortList(slow);
        return merge(l1,l2);
    }
};
```