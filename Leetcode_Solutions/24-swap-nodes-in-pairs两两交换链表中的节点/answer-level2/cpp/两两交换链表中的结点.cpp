用两个指针遍历链表并交换。
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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL)//空结点时
            return NULL;
        ListNode *p=head,*q=head->next,*t;//p是前结点，q是后结点
        if(q==NULL)
            return p;//只有一个结点
        else 
            t=q;//有多个结点，先保存要返回的链表的起始节点
        while(q!=NULL)
        {
            if(q->next==NULL)//最后只剩NULL时
            {
                p->next=NULL;
                q->next=p;
                break;
            }
                
            if(q->next!=NULL&&q->next->next==NULL)//最后只剩一个结点时
            {
                p->next=q->next;
                q->next=p;
                break;
            }
                
            if(q->next!=NULL&&q->next->next!=NULL)//两两交换
            {
                ListNode *s=q->next;
                q->next=p;
                p->next=s->next;
                p=s;
                q=s->next;
            }
         
        }
        return t;
    }
};