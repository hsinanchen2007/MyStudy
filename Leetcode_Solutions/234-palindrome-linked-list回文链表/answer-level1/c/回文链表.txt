```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


bool isPalindrome(struct ListNode* head){
    //本题是一道典型的快慢指针+翻转链表问题
    if(head==NULL||head->next==NULL)
        return true;
    //1.首先利用快慢指针找到链表的中点，然后沿中点翻转前半段链表并和后半段比较
    struct ListNode* fast=head->next;
    struct ListNode* slow=head;

    while(fast!=NULL&&fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    //需要区分节点是奇数个还是偶数个
    if(fast!=NULL)  //偶数个
    {
        struct ListNode *p=slow->next;  //此时p之前是链表的前半段，p之后是链表的后半段
        slow=head;
        //下面开始翻转链表
        while(slow!=p)
        {
            struct ListNode *r=slow->next;  //保存slow的后续节点
            slow->next=head;
            head=slow;                      //头插法
            slow=r;
        }
        slow=head;
        while(slow!=p&&p!=NULL)
        {
            if(slow->val!=p->val)
                return false;
            slow=slow->next;
            p=p->next;
        }
        return true;
    }
    else
    {
        struct ListNode *p=slow;
        slow=head;
        while(slow!=p)
        {
            struct ListNode *r=slow->next;  //保存slow的后续节点
            slow->next=head;
            head=slow;                      //头插法
            slow=r;
        }
        slow=head;
        struct ListNode* q=p->next;
        while(slow!=p&&q!=NULL)
        {
            if(slow->val!=q->val)
                return false;
            slow=slow->next;
            q=q->next;
        }
        free(p);
        return true;
    }
}
```
