### 解题思路
好像leetcode上面的链表都没有头节点，题目也没有声明，所以要构造虚拟的头节点

### 代码

```c
struct ListNode* removeElements(struct ListNode* head, int val){
    if ( !head ) {
        return head;
    }
    
    // 构造虚拟头节点
    struct ListNode *h = (struct ListNode *)malloc(sizeof(struct ListNode));
    h->next = head;
    struct ListNode *work = head, *pre = h;

    while ( work ) {
        if ( work -> val == val ) {
            pre -> next = work -> next;
        } else {
            pre = work;
        }
        work = work -> next;
    }
    return h->next;         // 这里return head有问题。。。
}
```