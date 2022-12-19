双指针法求解，一个指向奇数链表，另一个指向偶数链表，每次迭代后注意奇偶连接，然后迭代进行。
注意考虑pre和cur进行一次迭代后如何衔接，ListNode* tmp=pre->next表明每次衔接点的位置（如果用cur进行衔接的话会丢失一些元素），最后用pre->next->next=tmp可以保证奇偶链表衔接正常。
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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *pre=head,*cur=head->next;
        while(cur && cur->next){
            ListNode* tmp=pre->next;
            pre->next=cur->next;
            cur->next=cur->next->next;
            pre->next->next=tmp;
            
            pre=pre->next;
            cur=cur->next;
        }
        return head;
    }
};
```