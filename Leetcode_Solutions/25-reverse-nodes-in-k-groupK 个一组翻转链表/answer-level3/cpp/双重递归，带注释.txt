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
    ListNode* reverse(ListNode* head,int k){
        if(k==1) return head;
        ListNode* finalnode=reverse(head->next,k-1);
        head->next->next=head;
        return finalnode;//返回未排序时最后一个结点（即排序后第一个结点）      
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* p=head;
        for(int i=0;i<k;i++){
            if(p==NULL) return head;
            p=p->next;
        }//判断是否还可以反转
        ListNode* nexthead=p;
        ListNode* result=reverse(head,k);//反转函数，返回反转第一组后的头节点（只反转第一组）
        head->next=reverseKGroup(nexthead,k);
        return result;//返回本轮递归操作后的头节点。
        
    }
};
```
