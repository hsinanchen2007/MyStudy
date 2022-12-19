### 解题思路
学链表的时候听别人说，这好像是一道腾讯面试题，下面说思路。
search是快指针，mid是慢指针，mid移动一个，search就移动两个，search指针移动到结尾，mid就指向了中间结点，返回即可，不过这题头结点竟然存放了数据，所以判断一下如果head->next == NULL,直接返回头结点

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* middleNode(struct ListNode* head)
{
    struct ListNode *search;
    struct ListNode *mid;
    int mid_data;

    mid = search = head->next;
    if(mid == NULL)
    return head;
    while(search->next != NULL)
    {
        if(search->next->next != NULL)
        {
            search = search->next->next;
            mid = mid->next;
        }
        else
        {
            search = search->next;
        }
    }

    return mid;
}
```