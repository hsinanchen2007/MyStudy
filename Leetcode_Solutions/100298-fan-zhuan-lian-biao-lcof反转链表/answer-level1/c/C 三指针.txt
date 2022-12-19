
三指针解法：
a 用来指向要返回的头
b 用来保存下个的节点



// struct ListNode* reverseList(struct ListNode* head){
//     struct ListNode *a = NULL,*b = NULL;
//     while(head != NULL)
//     {
//         b = head->next;
//         head->next = a;
//         a = head;
//         head = b;
//     }
//     return a;
// } 