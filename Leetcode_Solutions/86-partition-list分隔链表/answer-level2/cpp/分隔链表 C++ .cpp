### 解题思路
第一种方法比较笨，通过遍历找到小于x的连续序列最后一个位置r和在r后面大于等于x的连续序列的最后一个位置h，通过指针的操作，将h后面的元素放到r后面就好了。
第一种方法比较笨，也比较难理解一点。
第二种方法是链表的拼接，新建一个小链表和大链表，遍历题目链表，小的元素接到小链表后，大的接到大链表后，最后将大的接在小的后面，返回小的链表开头就好了。
第二种方便比较好理解一点。但是效率可能没第一种高。
![image.png](https://pic.leetcode-cn.com/f6c1ec1f98c3d38b7a0bf6c682d07912e5956b6d2f7a09d956b180cdee6832c2-image.png)
### 代码

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
    ListNode* partition(ListNode* head, int x) {
        if(head==NULL) return NULL;
        ListNode *tou=new ListNode(0);
        tou->next=head;
        ListNode *h=tou;
        ListNode *r=tou;
        ListNode *tmp=NULL;
        while(h!=NULL && h->next!=NULL)
        {
            while(r->next!=NULL && r->next->val<x)
            {
                h=h->next;
                r=r->next;
            }
            while(h->next!=NULL && h->next->val>=x)
            {
                h=h->next;
            }
            if(r->next!=NULL && h->next!=NULL)
            {
                tmp=r->next;
                r->next=h->next;
                h->next=h->next->next;
                r->next->next=tmp;
                r=r->next;
            }
        }
        return tou->next;
    }
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *MinLink =new ListNode(0);
        ListNode* Minp=MinLink;
        ListNode *MaxLink =new ListNode(0);
        ListNode *Maxp=MaxLink;
        ListNode *tmp=head;
        while(tmp!=NULL)
        {
            if(tmp->val<x)
            {
                Minp->next=tmp;
                tmp=tmp->next;
                Minp=Minp->next;
                Minp->next=NULL;
            }
            else
            {
                Maxp->next=tmp;
                tmp=tmp->next;
                Maxp=Maxp->next;
                Maxp->next=NULL;
            }
        }
        Minp->next=MaxLink->next;
        return MinLink->next;
    }
};
```