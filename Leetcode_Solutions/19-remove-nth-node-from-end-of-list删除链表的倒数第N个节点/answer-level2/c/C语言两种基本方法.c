方法一：遍历两次
```
struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    if (head == NULL) return NULL;
    struct ListNode *curr = head;
    struct ListNode *curr1;
    struct ListNode *node_to_del;
    struct ListNode *dummy;
    int cnt = 0;
    int i = 0;
    while(curr != NULL)
    {
        cnt++;
        curr = curr->next;
    }

    node_to_del = (struct ListNode *)malloc(sizeof(struct ListNode));
    dummy = (struct ListNode *)malloc(sizeof(struct ListNode));
    dummy->next = head;
    curr1 = dummy;
    while ((curr1->next != NULL) && (i<cnt-n))
    {
        curr1 = curr1->next;
        i++;
    }
    node_to_del = curr1->next;
    if (node_to_del != NULL)
    {
        curr1->next = node_to_del->next;
    }
    free(node_to_del);
 

    return dummy->next;
}
```
方法二：双指针法（学习！）
```
struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    if (head == NULL) return NULL;
    struct ListNode *dummy;
    dummy = (struct ListNode *)malloc(sizeof(struct ListNode));
    dummy->next = head;
    struct ListNode *fast, *slow;
    fast = dummy;
    slow = dummy;

    while((n--)&&(fast->next != NULL))
    {
        fast = fast->next;  //使快慢指针相距n，快指针遍历结束时，慢指针的正好指向倒数第n个节点
    }
    while(fast->next != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = slow->next->next;
    
    return dummy->next;
}
```
