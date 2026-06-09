### 解题思路
用第二题链表相加的思路，这题区别就是**右对齐**，由于单向链表的特点，要做到右对齐，必须反转或者用**栈**结构做到。

### 代码一、原地破坏l1装答案与反转
+ 反转两个链表是肯定的，想要原地修改，那必须用一个链表来转答案
+ l1边装答案边反转，把短链接在l1。（其实也可以用于第二题那样做，最后反转得到答案）
![image.png](https://pic.leetcode-cn.com/b1d76b2f29e2930c5fa3fa97b7a12ecd9dedb1c1779cab863905854ea1b79b20-image.png)

```c
struct ListNode* reverseList(struct ListNode* head){
    struct ListNode *p = NULL, *q = NULL;
    while (head) {
        q = head->next;  // q获取下个结点
        head->next = p;  // 将次结点后接上p连上
        p = head;  // p作为头结点
        head = q;  // head继续前进
    }
    return p;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    if (!l1 || !l2) return l1 ? l1 : (l2 ? l2 : NULL);
    l1 = reverseList(l1);
    l2 = reverseList(l2);
    struct ListNode *prev = NULL, *curr;
    int carry = 0;
    do {  // 1.最短遍历到末尾前驱结点
        carry += l1->val + l2->val;
        l1->val = carry % 10;
        carry /= 10;
        curr = l1->next;  // curr先保存l1下节点
        l1->next = prev;  // 进行反转操作
        prev = l1;  // prev更新
        l1 = curr;
        l2 = l2->next;
    }while (l1 && l2);
    // 2.末尾连接操作
    l1 = l1 ? l1 : l2;
    while (l1) {  // 3.遍历反转l1后半部分并carry进位
        curr = l1->next;
        carry += l1->val;
        l1->val = carry % 10;
        carry /= 10;
        l1->next = prev;
        prev = l1;
        l1 = curr;
    }
    if (carry == 1) {  // 4.进位处理
        curr = (struct ListNode*)malloc(sizeof(struct ListNode));
        curr->val = carry;
        curr->next = prev;
        prev = curr;
    }
    return prev;
}
```
时间复杂度：O(max(m,n)),m,n表示两个链表长度
空间复杂度：O(1):不满足题意

### 代码二、正确姿势（不修改，新建节点）
使用栈进行对链表“反转”，这里只是存节点指针，没有改变原链表的指向。最后再返回结果时构建新的链表。（由于倒着构建链表，无需dummy辅助）。
```python []
class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        if not l1 or not l2:
            return l1 or l2
        stack1, stack2 = [l1], [l2]
        while stack1[-1].next:  # 1.入栈元素
            stack1.append(stack1[-1].next)
        while stack2[-1].next:
            stack2.append(stack2[-1].next)
        carry, prev = 0, None
        while stack1 or stack2 or carry:  # 最长遍历
            carry += (stack1.pop().val if stack1 else 0) + (stack2.pop().val if stack2 else 0)
            head = ListNode(carry % 10)
            carry //= 10
            head.next = prev  # 倒置连接
            prev = head  # prev更新
        return head
```
```c []
typedef struct LinkStack{
    struct ListNode *ptr;  // 链表结点指针
    struct LinkStack *next;  // 链栈指针
}StackNode, *StackPtr;

void push(StackPtr *stack, struct ListNode *node) {
    StackPtr q = (StackPtr)malloc(sizeof(StackNode));
    q->ptr = node;
    q->next = *stack;
    *stack = q;  // 头指针改变
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    if (!l1 || !l2) return l1 ? l1 : (l2 ? l2 : NULL);
    StackPtr stack1 = NULL, stack2 = NULL;
    while (l1) {
        push(&stack1, l1);
        l1 = l1->next;
    }
    while (l2) {
        push(&stack2, l2);
        l2 = l2->next;
    }

    struct ListNode *prev = NULL, *curr;
    int carry = 0;
    while (stack2 || stack1 || carry) {
        carry += (stack1 ? stack1->ptr->val : 0) + (stack2 ? stack2->ptr->val : 0);
        curr = (struct ListNode*)malloc(sizeof(struct ListNode));
        curr->val = carry % 10;
        carry /= 10;
        curr->next = prev;
        prev = curr;
        // 2.链栈的删除
        stack1 = stack1 ? stack1->next : 0;
        stack2 = stack2 ? stack2->next : 0;
    }
    return prev;
}
```
时间复杂度：O(max(m,n)),m,n表示两个链表长度
空间复杂度：O(m+n)，存两个链表节点花费的空间。
