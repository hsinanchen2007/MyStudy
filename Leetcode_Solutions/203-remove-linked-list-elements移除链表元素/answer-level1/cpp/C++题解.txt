一次遍历，由于头结点有数据，为了方便处理先处理头结点后面的数据，最后处理头结点，链表需要两个指针cur和pre，是为了删除，同时要记得释放内存空间！
```
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL)
            return head;
        ListNode *cur = head->next;
        ListNode *pre = head;
        while(cur != NULL)
        {
            if(cur->val == val)
            {
                ListNode *tmp = cur;
                pre->next = cur->next;
                cur = cur->next;
                delete tmp;
            }
            else
            {
                cur = cur->next;
                pre = pre->next;
            }
        }
        if(head->val == val)
        {
            ListNode *tmp = head;
            head = head->next;
            delete tmp;
        }            
        return head;
    }
};
```
