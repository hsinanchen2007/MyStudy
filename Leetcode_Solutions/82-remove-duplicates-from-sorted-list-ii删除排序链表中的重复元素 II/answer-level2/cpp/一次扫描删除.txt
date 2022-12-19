 这里的关键在于需要找到所有的重复元素，然后全部删除掉，所以start记录重复之前的那个元素，比如1 2 2 3 4 ，则start =1 ,first =2 second = 2 ,然后first和second后移动，记录有多少重复的元素，当first!=second时候，就可以删除start到second之间所有的重复元素了！！！！！！！
 这里依旧用到了重要的头结点。

```
class Solution
{
public:
    ListNode * deleteDuplicates (ListNode * head)
    {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode dummy (-1);
        dummy.next = head;
        ListNode *start = &dummy;
        ListNode *first = head;
        ListNode *second = head->next;
        int count = 0;
        while (second)
        {
            if (first->val == second->val)
            {
                if (count == 0)
                    count = 2;
                else
                    count++;

                first = second;
                second = second->next;
            }
            else
            {
                if (count)
                {
                    ListNode *from = start->next;
                    while (from && from->next != second)
                    {
                        ListNode *tmp = from;
                        from = from->next;
                        delete tmp;
                    }
                    start->next = second;
                    first = second;
                    second = second->next;
                    count = 0;
                }
                else
                {
                    start = first;
                    first = second;
                    second = second->next;
                }
            }

        }
        if(count)
        {
            ListNode* p = start->next;
            start->next = NULL;
            while(p)
            {
                ListNode* tmp = p->next;
                delete p;
                p = tmp;
            }
        }
        return dummy.next;
    }
};
```
