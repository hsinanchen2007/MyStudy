# 需要注意两个问题
## 第一：删除倒数第N个节点必须找到倒数第N+1个节点
## 第二：删除中间，首节点和尾节点是否有不同
- 首先将第一个指针先移动到合适位置
- 然后第两个指针一起移动，当前面一个到最后一个节点时，后面一个刚好到倒数第N+1个
- 移除
```
struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode* pre, *p;
    pre = head;
    p = head;
    int i=1;
    int grap = n+1;
    while(i!=grap)
    {
        p=p->next;
        i++;
    }
    if(p == NULL)
    {
         head = head->next;
         return head;
    }
    while(p->next)
    {
        pre = pre->next;
        p = p->next;
    }
    pre->next = pre->next->next;
    return head;
}

```
