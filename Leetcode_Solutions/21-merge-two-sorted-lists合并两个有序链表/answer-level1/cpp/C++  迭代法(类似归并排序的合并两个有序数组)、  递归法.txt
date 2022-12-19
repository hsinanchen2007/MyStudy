```cpp
//迭代法:
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

    //判空
    if (!l1)
    {
        return l2;
    }

    if (!l2)
    {
        return l1;
    }

    //先确定头节点
    ListNode* head = nullptr;
    if(l1->val <= l2->val)
    {
        head = l1;
        l1 = l1->next;
    }
    else
    {
        head = l2;
        l2 = l2->next;
    }

    //再确定其他节点
    ListNode* cur = head;
    while(l1 && l2)
    {
        if(l1->val <= l2->val)
        {
            cur->next = l1;
            l1 = l1->next;
        }
        else
        {
            cur->next = l2;
            l2 = l2->next;
        }
        cur = cur->next;
    }

    if(l1)
    {
        cur->next = l1;
    }

    if(l2)
    {
        cur->next = l2;
    }

    return head;
}


//递归法： 递归函数是每次返回小的节点，并在返回之前做好连接下个节点的调用
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

    if (l1 == nullptr)
    {
        return l2;
    }

    if (l2 == nullptr)
    {
        return l1;
    }

    if (l1->val <= l2->val)
    {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    }
    else
    {
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
}