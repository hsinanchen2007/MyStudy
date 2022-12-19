找到旋转点的位置，进行截断操作（为了方便起见，我们反向操作，找的是旋转点前一个点的位置）。

对k进行分情况讨论，设定num为链表的长度，我们现在求旋转点的位置，利用k进行查找，当k<num时，k=num-k，当k>=num时，k=num-k%num，
得到通式k=num-k%num，求解即可。
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next) return head;
        ListNode *dummy=new ListNode(-1),*pre=dummy;
        dummy->next=head;
        ListNode *p1=dummy,*p2=dummy;
        int num=0;
        while(p1->next){
            num++;
            p1=p1->next;
        }
        k=num-k%num;
        while(k){
            p2=p2->next;
            k--;
        }
        
        p1->next=dummy->next;
        dummy->next=p2->next;
        p2->next=NULL;
        
        return dummy->next;
        
    }
};
```