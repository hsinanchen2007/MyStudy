### 解题思路
先通过结构体p的遍历把链表长度计算出来，然后再根据长度从右向左计算各个位上的值并加起来。

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


int getDecimalValue(struct ListNode* head){
    int cnt=0,sum=0;
    struct ListNode* p=head;
    while(p)
    {
        cnt++;
        p=p->next;
    }
    while(head&&cnt>=0)
    {
        sum+=(head->val)*(int)pow(2,cnt-1);
        cnt--;
        head=head->next;
    }
    return sum;
}
```