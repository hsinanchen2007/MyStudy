### 解题思路
该题较为简单，解题思路如下：
* 定义一个获取链表长度的函数
* 获取链表长度len，并计算得出倒数第K个数对应在链表中正数的位置len-k
* 循环遍历链表到len-k的位置，并返回

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int listLength(struct ListNode *head)
{
    int len = 0;
    while(head != NULL)
    {
        head = head->next;
        len++;
    }
    return len;
}

struct ListNode* getKthFromEnd(struct ListNode* head, int k)
{
    //计算链表的长度
    int len = listLength(head);

    //计算倒数第K个节点对应的正数的位置
    int m = len-k;
    while(m > 0)
    {
        head = head->next;
        m--;
    }
    return head;
}
```
### 解题思路
参考别人的解法（更好的解法），用**双指针**实现了一遍，思路如下：
* 创建双指针p和q
* p先走K步，之后q再往前走，直到p == NULL时，跳出循环
* 返回q之前，需判断p是否向前走了K步

### 代码
``` c
struct ListNode* getKthFromEnd(struct ListNode* head, int k)
{
    //双指针
    struct ListNode *p = head;
    struct ListNode *q = head;

    int i = 0;
    while(p != NULL)
    {
        if(i>=k)
        {
            q = q->next;
        }
        p = p->next;
        i++;
    }
    return (i<k ? NULL:q);
}
```