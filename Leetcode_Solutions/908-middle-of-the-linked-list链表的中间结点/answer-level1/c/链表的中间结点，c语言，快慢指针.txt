### 解题思路
快慢指针啊。

### 代码

```c
//题里头说有头结点，实际上有个鸡儿？
struct ListNode* middleNode(struct ListNode* head){
    struct ListNode *p=head,*q=head;
    while(p && p->next){
        p = p->next->next;
        q = q->next;
    }
    return q;
}
```