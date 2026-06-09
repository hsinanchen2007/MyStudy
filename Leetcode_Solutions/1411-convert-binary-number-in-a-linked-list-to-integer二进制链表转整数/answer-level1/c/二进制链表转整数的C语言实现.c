### 解题思路
该题是对链表进行操作，将链表中的每个元素作为二进制数，将其转化为十进制数。解题思路如下：
* 入参检查
* 获取链表长度
* 循环遍历链表每个元素，并利用pow函数将其转化为对应的十进制数。

该解法耗费的时间较长，原因是由于使用了两个while循环，并且使用了库函数pow，这都增加了时间开销。

本题时间复杂度O(N)，空间复杂度O(1)。

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
    if(!head)
    {
        return 0;
    }

    int len = 0;
    while(head)
    {
        len++;
        head = head->next;
    }
    return len;
}

int getDecimalValue(struct ListNode* head)
{
    int sum = 0;
    if(!head)
    {
        sum = 0;
    }
    else
    {
        //获取链表长度
        int length = listLength(head);
        //循环遍历链表
        while(head)
        {
            sum += (int)pow(2,--length)*(head->val);
            head = head->next;
        }
    }
    return sum;
}
```