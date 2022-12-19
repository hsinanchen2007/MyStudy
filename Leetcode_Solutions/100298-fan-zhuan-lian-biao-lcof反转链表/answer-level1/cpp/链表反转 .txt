```C++
class Solution {
public:
    //以下是迭代版本
    ListNode* reverseList(ListNode* head) {
        if(head == NULL){
            return head;
        }
        ListNode * p = head;
        ListNode * q = p -> next;
        int flag = 0;
        while(q != NULL){
            ListNode * t = q -> next;
            q -> next = p;
            if(flag == 0){
                p->next = NULL;
                flag ++;
            }
            p = q;
            q = t;
        }
        return p;
    }
    //以下是递归版本
    ListNode * new_head;
    void reverse(ListNode * p, ListNode * head){
        if(head->next != NULL){
            reverse(head, head->next);
            head->next = p;
        }else{
            new_head = head;
            head->next = p;
        }
        return ;
    }
    ListNode* reverseList1(ListNode* head) {
        if(head == NULL)    return head;
        ListNode * first = NULL;
        reverse(first, head);
        return new_head;
    }
};
```