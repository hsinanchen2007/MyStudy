**核心思想：对数组的链表两两进行归并，将归并后的链表从前往后依次插入到数组中，代替原来已经没有用的数组元素。**
**一趟归并完成后，下一趟要归并的数组长度减少为当前数组长度的一半（如果当前数组长度为奇数需要加一）。**
**利用for循环动态维护数组的长度，直到下一趟数组长度为1，代表所有链表归并完毕**
**第一次写题解，可能表述不是很清楚，请各位大佬见谅**
```
class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.size() < 1)
            return nullptr;
        if (lists.size() == 1)
            return lists[0];
        int len = lists.size();
        int i = 1;
        for (i; i <= len / 2;)//
        {
            lists[i - 1] = sorttwolist(lists[2 * (i - 1)], lists[2 * (i - 1) + 1]);//为了不增大vector，不断地将两两归并的链表插入到vector的靠前的位置。
            if (i == len / 2) //当前数组，两两归并完成
            {
                if (len % 2 == 1) //数组长度为奇数，后面还有一个链表没有参与归并
                {
                    lists[i] = lists[len - 1];//把它插入到当前已归并完的数组的后一位
                }
                if(len / 2 == 1 && len % 2 == 0)//如果所有链表都归并到一个链表上了，代表归并结束。
                    break;
                //根据当前归并后的数组长度，更改数组长度，进行下一伦循环
                len = len / 2 + (len % 2);
                i = 0;
            }
            ++i;
        }
        return lists[0];
    }

    ListNode *sorttwolist(ListNode *t1, ListNode *t2)//将链表两两归并
    {
        ListNode *head = new ListNode(-1); //头结点
        ListNode *p = head;
        while (t1 && t2)
        {
            if (t1->val < t2->val)
            {
                p->next = t1;
                p = p->next;
                t1 = t1->next;
            }
            else
            {
                p->next = t2;
                p = p->next;
                t2 = t2->next;
            }
        }
        if (t1)
            p->next = t1;
        if (t2)
            p->next = t2;
        return head->next;
    }
};
```

