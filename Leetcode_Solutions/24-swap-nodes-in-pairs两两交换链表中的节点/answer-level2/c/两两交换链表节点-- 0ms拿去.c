# 思路
什么递归不递归的，我想不到，我只知道这道题就是删除节点插入节点
最开始弄个虚拟头节点⊙

p
⇓
⊙➙①➙②➙③➙④
.............⇑
.............q


开始p指向虚拟头， q指向②, 遍历， 第一次操作删除①，在②后面添加①(开辟新节点，让其val和①相等),然后更新p, q
**注意:**
如果链表为空或一个节点直接返回head;
结束条件，若偶数个节点则p->next == NULL时结束，奇数个节点则p->next->next == NULL时结束，两个条件分开写上
# 代码
0ms 代码拿去参考 :-D
```c
struct ListNode* swapPairs(struct ListNode* head){
    if(head == NULL || head->next == NULL) return head;
    struct ListNode node;
    node.next = head;
    struct ListNode* p = &(node);
    struct ListNode* q = head->next;
    printf("%d %d\n", p->next->val, q->val);
    while(1) {
        struct ListNode* add_node = (struct ListNode *)malloc(sizeof(struct ListNode));
        add_node->val = p->next->val;
        add_node->next = q->next;
        q->next = add_node;
        p->next = q;
        p = add_node;
        if(p->next == NULL) break;
        if(p->next->next == NULL) break;
        q = p->next->next;
    }
    return node.next;
}
```
