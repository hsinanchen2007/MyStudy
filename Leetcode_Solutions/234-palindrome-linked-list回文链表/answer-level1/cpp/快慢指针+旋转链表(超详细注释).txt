```
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *first=head,*second=head,*third=head,*updown=NULL;//first为快指针,,second为慢指针,,third为翻转链表的后方节点,updown为翻转链表的前方节点
        if(!(head&&head->next))
        return 1;
        while(first&&first->next)
        {
            first=first->next->next;//快指针走两步,,慢指针走一步
            third=second;//翻转指针的最后一个节点等于翻转前第一个节点
            second=second->next;
            third->next=updown;//类似与链表头插法,第一步是令第一个节点指针域指向NULL
            updown=third;
        }
        if(first)//链表长度为奇数,此时慢指针位于中点的数
        second=second->next;
        while(second)
        {
            if(second->val!=updown->val)
            return 0;
            second=second->next;
            updown=updown->next;
        }
        return 1;


    }
};
```