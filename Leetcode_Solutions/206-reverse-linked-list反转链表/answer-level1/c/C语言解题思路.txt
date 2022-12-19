### 解题思路
C语言，使用三个指针记录，第一个用来获取链表的总长度，两个指针分别交换彼此的值

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head){
    int length = 0;
    int first,last;
    int temp;
    struct ListNode* ptr1 = head;
    struct ListNode* ptr2 = head;
    struct ListNode* ptr3 = head;
    while(ptr1 != NULL)
    {
        length ++;
        ptr1 = ptr1 ->next;
    }
    first = 1;
    last = length;
    //printf("%d\n",length);
    int k = last - first;
    while(first < last)
    {
        temp = head -> val;
        for(int i = 0;i < k;i++)
        {
            ptr2 = ptr2 -> next;
        }
        head->val = ptr2 -> val;
        ptr2->val = temp;
        head = head->next;
        first ++;
        last --;
        k --;
        ptr2 = ptr3;
    }
    return ptr3;
}


```