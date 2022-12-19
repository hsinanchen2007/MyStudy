```
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
    ListNode* mergeTwoLists1(ListNode* l1, ListNode* l2){  //递归解法
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        ListNode* head;
        if(l1->val < l2->val)
        {
            head=l1;
            head->next=mergeTwoLists(l1->next, l2);
        }
        else
        {
            head=l2;
            head->next=mergeTwoLists(l1,l2->next);
        }
        return head;
    }
    ListNode* mergeTwoLists2(ListNode* l1, ListNode* l2){  //迭代1
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        ListNode* head=new ListNode(-1);
        ListNode* p=head;
        while(l1!=NULL && l2!=NULL)
        {
            if(l1->val>l2->val)
            {
                p->next=l2;
                p=p->next;
                l2=l2->next;
            }
            else
            {
                p->next=l1;
                p=p->next;
                l1=l1->next;
            }
        }
        if(l1!=NULL) p->next=l1;
        if(l2!=NULL) p->next=l2;
        return head->next;
    }
    ListNode* mergeTwoLists3(ListNode* l1, ListNode* l2) {       //迭代2
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        ListNode* head;
        ListNode* ans;
        ListNode* cur;   
        if(length(l1)>length(l2))     //取较长的链表作为主链表
        {
            head=l1;
            ans=l2;
        }
        else
        {
            head=l2;
            ans=l1;
        }
        while(ans!=NULL)
        {
            cur=ans->next;          //保留下一个节点
            head=merge(head, ans);
            ans=cur;
        }
        return head;
    }
private:
    int length(ListNode* l1)         //链表长度
    {
        int count=0;
        if(l1==NULL) return 0;
        while(l1 != NULL)
        {
            count++;
            l1=l1->next;
        }
        return count;
    }
    ListNode* merge(ListNode* head, ListNode* ans)   //head链表，ans结点（插入节点）
    {
        ListNode* p=head;
        ListNode* q=NULL;
        while(p!=NULL && p->val < ans->val)
        {
            q=p;           //待插入位置前一个位置
            p=p->next;     //待插入位置
        }
        if(p==head)        //头结点插入
        {
            ans->next=p;              //   2->4->8   1
            return ans;               // 1->2->4->8
        }
        q->next=ans;                 //     2->4->8   3
        ans->next=p;                 //  2->3->4->8
        return head;
    }
};
```
