### 解题思路
先计算next到最后需要的步数，然后判断步数的奇偶，最后得到找到中间节点的步数

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
    struct ListNode *a = head;
    struct ListNode *b = head;
    int count = 0;

    while(a->next != NULL)
    {
        a = a->next;
        count++;
    }
    int n = count / 2;
    if(count % 2 != 0) n++;

    for(int i = 0; i < n; i++)
    {
        b = b->next;
    }

    return b;
}
```