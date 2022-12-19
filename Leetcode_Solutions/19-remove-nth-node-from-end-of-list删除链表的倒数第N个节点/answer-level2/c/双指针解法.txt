struct ListNode* removeNthFromEnd(struct ListNode* head, int n)
{
    /* 
    *  str1指针指向head，str2后移N个
    *  当str2为NULL时，str1为需要删除的指针
    *  注意判断删除head节点的情况
    */
    struct ListNode *str1 = head;
    struct ListNode *str2 = head;

    for (int i = 0; i < n; i++) {
        str2 = str2->next;
        if (str2 == NULL) {
            return head->next;
        } 
    }


    while (str2->next != NULL) { 
        str1 = str1->next;
        str2 = str2->next;
    }

    str1->next = str1->next->next;

    return head;
}