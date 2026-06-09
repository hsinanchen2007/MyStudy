`
```
void reorderList(ListNode *head)
    {
        //Reorder List
        ListNode *fast = head, *slow = head, *last;
        ListNode *pre = nullptr;
        stack<ListNode *> st;
        while (fast != nullptr && fast->next != nullptr)
        {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        if (pre != nullptr)
            pre->next = nullptr;
        while (slow != nullptr)
        {
            st.push(slow);
            slow = slow->next;
        }
        pre = head;
        while (pre != nullptr)
        {
            ListNode *tem = pre->next;
            pre->next = st.top();
            last = pre->next;
            st.pop();
            pre->next->next = tem;
            pre = tem;
        }
        if (!st.empty())
        {
            last->next = st.top();
            st.pop();
            last->next->next = nullptr;
        }
    }
```

`
