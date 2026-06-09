### 解题思路
当然原地修改是不对的，哈哈哈。这题跟第三题：链表相加一模一样！

1. 由于需要原地修改，那么末尾结点前驱节点是必须拿到的（否则你先全部遍历完，然后再取）
2. 进位处理，相加取余，最后还需要判断carry=1（这种只可能在链表终止，比如2->4->3,5->6->6)

+ 最短遍历，取到尾结点前驱节点，同时carry进位存储
+ 在上述遍历后，定有其中一个结束或者一起结束，都获得前结点，还要对此结点进行加减操作
+ 判断上步是谁终止，将长的连l1上，然后继续运算。如果一起断，那么最后判断carry=1额外申请结点

### 代码
> 1.原地修改
```c
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *head = l1;
    int carry = 0;  // 表示进位0
    // 1.使用最短遍历，将结果放在链表1中
    while (l1->next && l2->next) {
        carry += l1->val + l2->val;  // 先用carry存两个链表值
        l1->val = carry % 10;  // 放在链表1节点上并返回l1
        carry /= 10;  // 进位标志就在这里(1或0)
        l1 = l1->next;
        l2 = l2->next;
    }
    // 获得终止前驱节点便于连接操作
    carry += l1->val + l2->val;  // 上轮循环终止carry
    l1->val = carry % 10;
    carry /= 10;
    l1->next = l2->next ? l2->next : l1->next;  // 把l2连在l1上
    while (l1->next && carry) {  // 这里carry必要，因为链表还长，carry=0没必要遍历
        l1 = l1->next;
        carry += l1->val;
        l1->val = carry % 10;
        carry /= 10;
    }
    if (carry == 1) {
        l1->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        l1->next->val = carry;
        l1->next->next = NULL;
    }
    return head;
}
```

> 2.有dummy结点辅助建表

```c
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *p, *q;
    struct ListNode *dummy = (struct ListNode *)malloc(sizeof(struct ListNode));
    q = dummy;
    int carry = 0;  // 进位
    while (l1 || l2 || carry) {  // 最长遍历与carry进位1处理
        p = (struct ListNode*)malloc(sizeof(struct ListNode));
        carry += (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
        p->val = carry % 10;
        carry /= 10;
        l1 = l1 ? l1->next : 0;
        l2 = l2 ? l2->next : 0;  // 每次需要判断，因为l1->val取值问题
        p->next = NULL;
        q->next = p;  // 1.有dummy直接连接此轮p结点
        q = p;  // 2.q保存此轮p，到下轮就是p的上节点
    }
    return dummy->next;
}
```

> 3.无dummy辅助建表，多一个判断
```c
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *head = NULL, *p, *q;
    int carry = 0;  // 进位
    while (l1 || l2 || carry) {  // 最长遍历与carry进位1处理
        p = (struct ListNode*)malloc(sizeof(struct ListNode));
        carry += (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
        p->val = carry % 10;
        carry /= 10;
        l1 = l1 ? l1->next : 0;
        l2 = l2 ? l2->next : 0;  // 每次需要判断，因为l1->val取值问题
        p->next = NULL;
        if (!head) head = p;  // 1.无dummy结点做法，头节点连上
        else q->next = p;  // 3.2中得到的结点向后连接此轮p
        q = p;  // 2.q保存此轮p，到下轮就是p的上节点
    }
    return head;
}
```

## 拓展（右对齐）
使用栈就搞定了，反转链表也行。
```python3
def addTwoNumbers(l1: ListNode, l2: ListNode) -> ListNode:
    if not l1 or not l2: return l1 or l2
    stack1, stack2 = [l1], [l2]
    carry, prev = 0, None
    while stack1[-1].next:
        stack1.append(stack1[-1].next)
    while stack2[-1].next:
        stack2.append(stack2[-1].next)
    while stack1 or stack2 or carry:
        carry += (stack1.pop().val if stack1 else 0) + (stack2.pop().val if stack2 else 0)
        head = ListNode(carry % 10)
        carry //= 10
        head.next = prev
        prev = head
    return head
```
需要注意的就是给0->3->5,2->5这种右对齐，前面的0会照样返回，具体看题要求
扩展题：[445.两数相加Ⅱ]((https://leetcode-cn.com/problems/add-two-numbers-ii/))