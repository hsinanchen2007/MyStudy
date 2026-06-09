### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* middleNode(struct ListNode* head){
    struct ListNode * tmp=head;
    int counter=0;
    int i;
    while(tmp)
    {
        tmp=tmp->next;
        ++counter;
    }
    counter=counter/2+1;\\确定输出的是第几位
    tmp=head;
    for(i=1;i<counter;i++)\\确定循环次数
    {
        tmp=tmp->next;
    }
    return tmp;
}
```