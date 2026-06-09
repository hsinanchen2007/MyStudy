

``` C++
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
    bool isPalindrome(ListNode* head) {
        if(head==NULL||head->next==NULL)
            return true;
        //寻找中间节点
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast&&fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        //翻转后半部分节点
        ListNode* cur=slow;
        ListNode* post=cur->next;
        ListNode* pre=NULL;
        while(cur)
        {
            cur->next=pre;
            pre=cur;
            cur=post;
            post=post?post->next:NULL;
        }
        //比较翻转后的链表与未翻转的链表
        while(pre)
        {
            if(pre->val!=head->val) return false;
            pre=pre->next;
            head=head->next;
        }
        return true;
        
    }
};
```