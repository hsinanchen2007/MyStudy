### 解题思路
快慢指针判断链表是否有环

### 代码

```c
bool hasCycle(struct ListNode *head) {
    if(!head){
        return false;
    }
    struct ListNode *p=head,*q=head->next;
    while(p != q){
        if(q && q->next){
            p = p->next;
            q = q->next->next;
        }else{
            return false;
        }
    }
    return true;
}
```