### 解题思路
一趟扫描思路很简单，但不少坑要踩。
我们先让rear指针向前走，走了n个元素之后，再让aim指针往前行。并且希望aim能够停在倒数第n个元素的前一个。
下面来踩坑：
1. 首先你要判断是否为空字符串
2. 我们有两个指针，如果数组只有一个元素，很容易造成越界。这一点要仔细检查。
3. 如果是删除第一个元素，我们的返回值该是什么？这里我做了一个if的判断。

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
    struct ListNode* rear = head;
    struct ListNode* aim = head;

    if (head == NULL)
    {
        return NULL;
    }
    
    while (n--)
    {
        rear = rear->next;//停在第n个节点的
    }
    if (rear == NULL)//删除第一个元素
    {
        aim = aim->next;
        return aim;
    }
    while (rear->next != NULL) 
    {
        rear = rear->next;
        aim = aim->next;//最终会停在倒数第n个节点的前一个
    }

    rear = aim->next;
    aim->next = rear->next;
    free(rear);

    return head;

}
```