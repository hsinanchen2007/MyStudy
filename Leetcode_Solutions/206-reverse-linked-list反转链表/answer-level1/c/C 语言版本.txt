主要思路：从前往后，挨个拆下节点，然后反向组合成链表
例如： 1 --> 2 --> 3 --> 4 --> NULL
初始状态：cur 指针指向首节点【1】，dismount 代表将要被拆下的节点，pre 代表被拆下节点反向连接成的新链表
过程：
1. 若cur不是最后一个节点，dismount 指向 cur，此时 dismount --> 1;
2. cur 此时可以向后移一个节点，此时 cur --> 2;
2. 将 dismount 拆下来，即 dismount->next = NULL; 反向连接到 pre 链表上，此时的pre： 1 --> NULL，cur：2 --> 3 --> 4 --> NULL
3. 重复以上过程，pre最终变成：4 --> 3 --> 2 --> 1 --> NULL ,cur 所有节点都被拆下来
4. 返回 pre 

```c []
struct ListNode* reverseList(struct ListNode* head){
    if(head == NULL){
        return  head;
    }
    struct ListNode *pre = NULL; // 代表被拆下节点反向连接成的新链表
    struct ListNode *dismount; // 代表将要被拆下的节点
    struct ListNode *cur = head;
    while (cur) {
        dismount = cur;
        cur = cur->next;
        dismount->next = NULL;
        if(pre==NULL){
            pre = dismount;
        }else{
            dismount->next = pre;
            pre = dismount;
        }
    }
    return pre;
}
```
