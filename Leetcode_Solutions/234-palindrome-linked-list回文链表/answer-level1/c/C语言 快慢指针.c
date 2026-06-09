![image.png](https://pic.leetcode-cn.com/60e73bf54bfb44d70ffd8d1915572d0280ac655115f1af76b71a8ad705618d36-image.png)
```
bool isPalindrome(struct ListNode* head){
    if(head == NULL || head->next == NULL)
        return true;
    //找到中点
    struct ListNode* fast = head->next->next;
    struct ListNode* slow = head->next;
    while(fast!=NULL&&fast->next != NULL){
        slow = slow->next;
        
        fast = fast->next->next;
    }
    //翻转前半部分链表
    struct ListNode* pre = NULL;
    struct ListNode* curr = head;
    while(curr != slow){
        struct ListNode* temp = curr->next;
        curr->next = pre;
        pre = curr;
        curr = temp;
    }
    if(fast!=NULL)
        slow = slow->next;
    while(pre!=NULL){
        if(pre->val!=slow->val)
            return false;
        pre = pre->next;
        slow = slow->next;
    }
    return true;
}
```

