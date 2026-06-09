```
ListNode *middleNode(ListNode *head) {
    ListNode *quick, *slow;
    if (head == NULL || head->next == NULL)
        return head;
    else {
        quick=head->next;
        slow=head;
        while (quick->next!=NULL){
            slow=slow->next;
            quick=quick->next;
            if (quick->next!=NULL)
                quick=quick->next;
            else return slow;
        }
    }
    return slow->next;
}
```
同时检查下一步是否到链表的尾部，若长度为偶数则在while循环开始前便会跳出，此时慢指针必处于中间双结点的前一个，因此需返回慢指针的下一个结点，奇数则正好为目标节点