### 解题思路
两个指针，一个返回，一个先遣。
先遣和返回之间保持K个节点的距离。
先遣到达末尾之后的空指针时，返回指针即为所求。

注意：控制好距离、看好是否有头结点。

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* getKthFromEnd(struct ListNode* head, int k){
    struct ListNode* p=head;
    struct ListNode* q=head;
    int i=k;
    while(i-->0)
    p=p->next;
    while(p!=0)
    {
        p=p->next;
        q=q->next;
    }
    return q;
}
```