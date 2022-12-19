题解里面貌似没有这种，基本都是奇链表和偶链表拼接。然后这个不需要额外的链表，只要四个节点。感觉可以写成递归，我就直接循环了。
大致思路如图，
![IMG_4092.JPG](https://pic.leetcode-cn.com/d2318bdb978953025a3a9d38157330bc035dc4a898356717320fa3d289097f67-IMG_4092.JPG)
![IMG_4093.JPG](https://pic.leetcode-cn.com/0291a612540fc5b18027377ec1d3821d5f1cddcd6984f5962180cadb54c8ea01-IMG_4093.JPG)

```
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head)
            return NULL;
        if(!head->next || !head->next->next)
            return head;
        ListNode *begin = head->next;
        ListNode *end;
        ListNode *a = begin;
        ListNode *b = a->next;
        while(a!=NULL && b!=NULL)
        {
            b = a->next;
            int temp = a->val;
            a->val = b->val;
            b->val = temp;
            if(b->next == NULL || b->next->next == NULL)
            {
                end = a;
                break;
            }
            a = b->next;
        }
        ListNode *print = head;
        while(print!=NULL)
        {
            print = print->next;
        }
        if(begin == end)
            return head;
        begin = begin->next;
        a = begin;
        b = a->next;
        while(true)
        {
            while(a && b)
            {
                int temp = a->val;
                a->val = b->val;
                b->val = temp;
                if(b == end)
                {
                    end = a;
                    break;
                }
                a = b->next;
                if(a == end)
                {
                    end = a;
                    break;
                }
                b = a->next;
            }
            if(begin == end)
                break;
            begin = begin->next;
            a = begin;
            b = a->next;
        }
        return head;
    }
};
```

第一个循环找到begin与end，begin前为奇数组前一部分，end后为偶数组后一部分。

第二个循环，内循环不断地交换begin与end之间数字，外循环则更新begin与end，然后又进入内循环，直到满足终止条件。