### 解题思路
- 建立一个index指针end，指向链表尾，也就是待删除结点p的后第n个结点，由于起始p指向链表头，所以先遍历令end指向链表第n个结点。再同时遍历end和p，当end指向链表尾时停止遍历，此时由于end和p间隔为n，所以p指向的为倒数第n个结点。
- 此外由于要进行删除结点的操作，声明了一个指针pre指向p的前驱。
- 有一个特殊情况是当删除的元素为第一个结点时，n=链表长度，end经过第一次遍历后已经指向null，不会和p再进行后面的遍历。pre和p都指向第一个结点，所以需要手动删除第一个结点。


### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode *end = head;
    struct ListNode *p = head;
    struct ListNode *pre = head;
    int i = 0;
    while (i < n)
    {
        end = end->next;
        i++;
    }
    if (!end){//若删除的为第一个元素
        head=head->next;
    }
    else
    {
        while (end)
        {
            pre = p;
            p = p->next;
            end = end->next;
        }
        pre->next = p->next;
        free(p);
    }

    return head;
}
```