struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *node = (struct ListNode*) malloc (sizeof (struct ListNode));
    struct ListNode *temp;
    struct ListNode *p;
    temp = node;
    p = temp;
    int flag = 0;
    int sum = 0;
    while (l1 != NULL || l2 != NULL) {
        p = node;
        int x = (l1 != NULL) ? l1->val : 0;
        int y = (l2 != NULL) ? l2->val : 0;
        sum = x + y + flag;
        if (sum > 9) {
            sum = sum % 10;
            flag = 1;
        } else {
            flag = 0;
        }
        node->val = sum;
        node->next = (struct ListNode*) malloc (sizeof (struct ListNode));
        node = node->next;
        if (l1 != NULL) {
            l1 = l1->next;
        }else {
            l1 = NULL;
        }
        if (l2 != NULL) {
            l2 = l2->next;
        } else {
            l2 = NULL;
        }
    }  
    if (flag == 1) {
        p = node;
        p->val = 1;
    }
    p -> next = NULL;
    return temp;
}