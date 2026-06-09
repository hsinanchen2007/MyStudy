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
    ListNode* partition(ListNode* head, int x) {
        ListNode* dummy=new ListNode(-1);
        dummy->next=head;
        ListNode *cur=head,*pre=dummy;//cur记录排好序的最右的不小于x的节点
        //pre记录排好序的最右的小于x的节点
        
        while(pre->next && pre->next->val<x)
            pre=pre->next;  //找到第一个大于x的节点
        cur=pre;      //防止pre->next为空节点，故不写cur=pre->next
        
        while(cur->next){
            if(cur->next->val<x){
                ListNode *t=cur->next;
                cur->next=t->next;
                t->next=pre->next;
                pre->next=t;
                
                pre=pre->next;
            }else
                cur=cur->next;
        }
        return dummy->next;
        
    }
};
```