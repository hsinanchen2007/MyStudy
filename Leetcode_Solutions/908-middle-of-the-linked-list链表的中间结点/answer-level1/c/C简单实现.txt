### 解题思路
直接求链表长度，取len/2+1位置的元素

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


int getLen(struct ListNode* head)
{
    //获取非空链表的元素个数
    int len ;
    struct ListNode* temp;

    temp = head;
    len = 0;

    while(temp)
    {
        len++;
        temp = temp->next;
    }
    return len;
}
struct ListNode* getEle(struct ListNode* head,int location)
{
    //获取指定位置的元素
    struct ListNode* temp;
    int cur ;

    temp = head;
    cur = 1 ;
    
    while(cur<location)
    {
        temp = temp->next;
        cur++;
    }

    return temp;
}

struct ListNode* middleNode(struct ListNode* head){
    int length = getLen(head);

    return getEle(head,length/2+1);
}
```