### 解题思路
先利用快慢指针寻找到中间位置，然后将后半部反转进行比较，比较容易错的地方是一些边界处

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
    bool isPalindrome(ListNode* head) {
        if(head==NULL||head->next==NULL)
            return true;
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast!=NULL&&fast->next!=NULL&&fast->next->next!=NULL)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        if(slow==head)//只有两个元素
        {
            if(head->val==head->next->val)
                return true;
            else
                return false;
        }
        ListNode* pre;
        ListNode* cur;
        ListNode* next;
        pre=slow;
        cur=pre->next;
        while(cur!=NULL)
        {
            next=cur->next;
            cur->next=pre;
            pre=cur;
            cur=next;
        }
        slow->next=NULL;
        ListNode* st=head;
        while(st!=NULL)
        {
            if(st!=NULL&&st->val!=pre->val)
                return false;
            pre=pre->next;
            st=st->next;
        }
        return true;
    }
};
```