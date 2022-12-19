### 解题思路
该题应用了**链表反转和双指针**的解法，解题思路如下：
* 入参判断
* 计算链表总长度
* 创建双指针prev和curr，并将curr指针移动到链表中间
* 将curr指针当作头节点，并反转链表
* 循环遍历两条链表，并比较链表节点的值

**Note:** 该解法练习了**双指针解法**，**链表反转**和**链表遍历**。虽说时间消耗未达到100%，但练习链表处理的基本操作。

本题的时间复杂度为O(N),空间复杂度为O(1)。

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
    if(!head)
    {
        len = 0;
    }
    else
    {
        while(head)
        {
            len++;
            head = head->next;
        }
    }
    return len;
}

struct ListNode* reverseList(struct ListNode* head)
{
    if(!head)
    {
        return NULL;
    }

    struct ListNode *newHead = NULL;
    struct ListNode *tmp;
    while(head)
    {
        tmp = head->next;
        head->next = newHead;
        newHead = head;
        head = tmp;
    }
    return newHead;
}

bool isPalindrome(struct ListNode* head)
{
    //入参检查
    if(!head)
    {
        return true;
    }

    //计算链表长度
    int length = listLength(head);

    //双指针遍历链表
    struct ListNode *prev = head;
    struct ListNode *curr = head;

    //计算curr指针需要移动的长度
    int len = 0;
    if(length%2 == 0)
    {
        len = length/2+1;
    }
    else
    {
        len  = length/2+2;
    }

    //移动curr指针到链表中间
    for(int i=1; i<len; i++)
    {
        curr = curr->next;
    }

    //将curr作为头节点，反转链表
    struct ListNode *newhead = reverseList(curr);

    //循环遍历两条链表，并比较链表节点的值是否相同
    while(newhead)
    {
        if(prev->val != newhead->val)
        {
            return false;
        }
        prev = prev->next;
        newhead = newhead->next;
    }
    return true;
}


```