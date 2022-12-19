参考约瑟夫环，考虑把链表拆开，找到开头，将链表重组，再考虑几种特殊情况，算法可以再优化


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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* begin;
        ListNode* newbegin;
        int count=0;
        int num;
        begin=head;
        if(head==NULL||head->next==NULL||k==0)// if the list only has one or zero number
        {
            return head;
        }
        while(begin!=NULL)
        {
            count++;
            begin=begin->next;
        }
        num=count; //recond the number
        count=count-(k%count); 
        begin=head;
        while(count!=0)
        {
            count--;
            begin=begin->next;
        }
        if(begin==NULL) //times same as the number
        {
            return head;
        }
        newbegin=begin;
        while(num>1)
        {
            if(begin->next==NULL)
            {
                begin->next=head;
            }
            num--;
            begin=begin->next;
        }
        begin->next=NULL;
        return newbegin;
    }
};