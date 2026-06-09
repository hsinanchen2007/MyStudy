很朴素的想法，既然是反转一部分链表，那就会把链表分割成3部分：反转前的一部分 反转的部分  反转后的一部分，那就只需要对这3部分分别处理即可，然后将三部分再拼接在一起就好了
```
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* pBefoerHead = NULL;
        ListNode* pBeforeTail = NULL;
        ListNode* pReserveHead = NULL;
        ListNode* pReserveTail = NULL;
        ListNode* pAfterHead = NULL;
        int i = 1;
        while(head != NULL)
        {
            // 反转部分之前的链表
            if(i < m)
            {
                // 第一个节点，就是反转前的头节点
                if(i == 1)
                {
                    pBefoerHead = head;
                }
                pBeforeTail = head;
                head = head->next;
            }
            // 反转部分之后的链表
            else if(i > n)
            {
                if(i == (n+1))
                {
                    pAfterHead = head;
                }

                head = head->next;
            }
            // 反转部分的链表
            else
            {
                // 遇到的第一个节点，是最后的尾节点，是初始化的头节点
                if(i == m)
                {
                    pReserveHead = head;
                    pReserveTail = head;
                }
          
                ListNode* temp = head;
                head = head->next;
                temp->next = pReserveHead;
                pReserveHead = temp;
            }
            i++;
        }

        // 返回头
        ListNode *rspHead = NULL;
        if(NULL != pBefoerHead)
        {
            rspHead = pBefoerHead;
        }
        else if(NULL != pReserveHead)
        {
            rspHead = pReserveHead;
        }
        else if(NULL != pAfterHead)
        {
            rspHead = pAfterHead;
        }

        // 将三部分拼接在一起
        if(NULL != pBeforeTail)
        {
            pBeforeTail->next = pReserveHead;
        }

        if(NULL != pReserveTail)
        {
            pReserveTail->next = pAfterHead;
        }

        return rspHead;
    }
};
```

