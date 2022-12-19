### 解题思路
两种方法：
1. 迭代 注意当修改了当前节点的next后，无法找到后续节点，因此在修改前需用一个指针指向下一个节点。这一过程最好在判断当前节点非空后，因为若在cur移动后立刻更新next，可能出现cur已经为空的情况，这时无法获取cur->next。
2. 递归 个人的理解是，返回的p指针是新链表的起点，其一直未改变，而真正反转的工作是由后面的两个语句完成的，这两个语句延长了以p为头结点的链表。

### 代码
```
//迭代法
struct ListNode* reverseList(struct ListNode* head){
    struct ListNode* prev = NULL;
    struct ListNode* cur = head;
    struct ListNode* next = NULL;
    while(cur){
        next = cur->next;//放在此处，相当于确保了一定有cur->next  
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}
```

```
//递归法
struct ListNode* reverseList(struct ListNode* head){
    if(head==NULL||head->next==NULL)
        return head;
    struct ListNode* p = reverseList(head->next);//此处返回反转后开始的节点
    head->next->next = head;//反转操作是对当前节点而言的
    head->next = NULL;
    return p;
}
```