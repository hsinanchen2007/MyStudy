### 解题思路
模仿中文维基百科写的
`https://zh.wikipedia.org/wiki/%E5%BD%92%E5%B9%B6%E6%8E%92%E5%BA%8F`

### 代码

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL)
        {
            return head;
        }
        int len = 0;
        ListNode *p = head;
        while(p != NULL)
        {//求链表长度
            len++;
            p = p->next;
        }
        //迭代归并排序
        ListNode *dummyHead = new ListNode(-1); // 
        dummyHead->next = head;
        ListNode *leftPre = new ListNode(-1);
        ListNode *rightPre = new ListNode(-1);
        for(int seg = 1; seg < len; seg += seg)
        {
            ListNode *pre = dummyHead;
            ListNode *left = pre->next;
            ListNode *right = pre->next;
            leftPre->next = left;
            rightPre->next = right;
            for(int start = 0; start < len; start += seg*2)
            {                   
                int low = start;
                int mid = min(start + seg, len);
                int high = min(start + seg*2, len);
                int start1 = low, end1 = mid, len1 = end1 - start1;
                int start2 = mid, end2 = high;

                //先把左边断开
                len1 -= 1;   //
                while(len1 > 0)
                {
                    right = right->next;
                    rightPre->next = right;
                    len1--;
                }
                rightPre->next = right->next;
                right->next = NULL;    //断开,right现在指向leftPart最后一个节点
                right = rightPre->next;

                while(start1 < end1 && start2 < end2)
                {
                    if(left->val <= right->val)
                    {
                        pre->next = left;
                        pre = pre->next;
                        left = left->next;
                        leftPre->next = left;
                        start1++; 
                    }
                    else
                    {
                        pre->next = right;
                        pre = pre->next;
                        right = right->next;
                        rightPre->next = right;
                        start2++;
                    }
                }
                while(start1 < end1)
                {
                   pre->next = left;
                   pre = pre->next;
                   left = left->next;
                   start1++;
                }
                while(start2 < end2)
                {
                    pre->next = right;
                    pre = pre->next;
                    right = right->next;
                    start2++;
                }
                //还本次剩下的部分的第一个节点指针，由right指着
                rightPre->next = right;
                left = right;
                leftPre->next = left;
             }
        }
        return dummyHead->next;
    }
};
```
想画个图来着，还有期末考试，算了，你们自己画吧