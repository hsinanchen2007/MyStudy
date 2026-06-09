```
struct ListNode* deleteDuplicates(struct ListNode* head)
{
    if( !head )
        return NULL;
    if( !head->next )
        return head;
    struct ListNode *headnode = (struct ListNode *)malloc(sizeof(struct ListNode));
    headnode->next = head;
    head = headnode;                                // 虚拟头节点 便于对第一个节点进行删除操作
    
    struct ListNode *slow = head->next ,*fast = head->next->next;           // 快慢指针 快指针始终比慢指针多移动一位
    struct ListNode *pre = head;                    // 三指针 pre为前驱指针用于删除操作
    
    if( !fast->next )            // 对只存在两个元素的链表进行判断
    {
        if( fast->val == slow->val )
            return NULL;
        return head->next;
    }
    while( fast )
    {
        if( fast->val == slow->val )              
        {
            while( fast && fast->val == slow->val )           // 判断接下来的节点是否与前两个相等的节点相等
            {
                fast = fast->next;
                slow = slow->next;
            }
            pre->next = fast;               // 当后继节点与前两个相等的节点不相等时 跳出while循环 将pre->next指向fast (即第一个不相等节点) ? 删除其间相等的节点?
            if( fast )                // 判断fast->next 是否为空 若非空则进位 继续判断
            {
                slow = fast;
                fast = fast->next;
            }
        }
        else                                // 不相等情况下 三指针各进一位 继续比较 
        {
            fast = fast->next;              
            slow = slow->next;
            pre = pre->next;
        }
    }
    return head->next;
}
```
