执行用时 :12 ms, 在所有 C 提交中击败了96.31%的用户
内存消耗 :7.3 MB, 在所有 C 提交中击败了100.00%的用户


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){

    int num = 0, carry = 0, index = 0, i;
    int num_ret[100] = {0};
    struct ListNode *head, *current;
    while(l1 || l2)
    {
        carry = 0;
        num = num_ret[index];
        if(l1)num+=l1->val;
        if(l2)num+=l2->val;
        if(num >= 10)
        {
            num -= 10;
            carry = 1;
        }
        num_ret[index++] = num;
        num_ret[index] = carry;
        
        if(l1)l1=l1->next;
        if(l2)l2=l2->next;

    }

    index += carry；

    head = (struct ListNode *)malloc(sizeof(struct ListNode) * index);
    current = head;
    
    for(i = 0; i < index; i++)
    {
        current->val = num_ret[i];
        if(i == index - 1)
        {
            current->next = NULL;
        }
        else
        {
            current->next = head + i + 1;
            current = current->next;
        }
    }

    return head;
}