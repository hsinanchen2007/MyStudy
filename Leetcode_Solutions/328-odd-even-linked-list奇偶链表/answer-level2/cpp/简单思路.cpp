### 解题思路

**思路是取分两串来进行串联
序号为奇数的串在一起，序号为偶数的串在一起
最后通过序号为奇数串的尾节点与序号为偶数串的头结点相连**

### 代码

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) 
    {
        ListNode *pre=head;
        ListNode *now=NULL;
        ListNode *cur=NULL;
        if(pre!=0)
            cur=head->next;
        if(pre==NULL||cur==NULL)
            return head;
        while(head->next!=0 && head->next->next!=0)
        {
            now=head->next;
            head->next=now->next;
            head=now->next;
            now->next=now->next->next;
            now=head->next;
        }
        if(head!=0)
            head->next=cur;
        else
            now->next=cur;
        return pre;
    }
};
```