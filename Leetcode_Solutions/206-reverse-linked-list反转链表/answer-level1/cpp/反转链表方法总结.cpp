方法1：简单易懂

`思路：在链表元素个数>1的情况下，先将链表的前两个结点反转，再将后面剩余的结点逐个添加到首端。`



```

struct ListNode* reverseList(struct ListNode* head){
    if (head == NULL || head -> next == NULL)//空链表或只有一个结点的链表
        return head;
    struct ListNode *p = head -> next, *q = head -> next -> next, *t;//q从第3个结点开始，t为q的下一个结点，防止断链

    p -> next = head;
    head -> next = NULL;//将链表的前两个结点反转，为后面在头部逐个添加结点做准备
    while (q){
        t = q -> next;//t指向q的下一个结点
        q -> next = p;//q连上p
        p = q;//p指向其前一个结点（向前移动一位）
        q = t;//q向后移动
    }
    return p;
}

```
方法2：

```

struct ListNode* reverseList(struct ListNode* head){
    struct ListNode *pre = NULL, *nex;//pre表示新表的首结点，初始化为NULL,使新表尾端指向空，nex记录顺序遍历的下一结点
    while (head){
        nex = head -> next;//记录下一结点
        head -> next = pre;//当前遍历的结点连接pre
        pre = head;//pre指向当前结点，当前结点成为新表的首结点
        head = nex;//指向当前结点下一结点，所以nex的作用在于辅助遍历，防止断链
    }
    return pre;//返回新表首结点
}

```

方法3：

`思路：第2个节点到第n个节点，依次逐节点插入到第1个节点(head节点)之后，(n-1)次这样的操作结束之后将首节点挪到新表的表尾即可。`
```
struct ListNode* reverseList(struct ListNode* head){
    if (head == NULL || head -> next == NULL)
        return head;
    ListNode *p = head -> next, *q;

    while (p -> next != NULL){
        q = p -> next;
        p -> next = q -> next;
        q -> next = head -> next;
        head -> next = q;
    }
    p -> next = head;//相当于成环  
    head = p -> next -> next;//新head变为原head的next  
    p -> next -> next = NULL;//断掉环

    return head;
}

```
方法4：

```
struct ListNode* reverseList(struct ListNode* head){
    if (head == NULL || head -> next == NULL)
        return head;
    struct ListNode *front = (struct ListNode*)malloc(sizeof(struct ListNode));
    front -> next = head;
    struct ListNode *tail = front -> next;
    struct ListNode *t;
    while (tail -> next){
        t = tail -> next;
        tail -> next = t -> next;
        t -> next = front -> next;
        front -> next = t;
    }
    return front -> next;
}
```

方法5：递归

自己还不能深刻理解递归，这里只是提供别人的方法。望指点！
```

struct ListNode* reverseList(struct ListNode* head){
    if (head == NULL)
        return NULL;
    if (head -> next == NULL)
        return head;
    struct ListNode *newHead = reverseList(head -> next);
    head -> next -> next = head;
    head -> next = NULL;
    return newHead;
}

```


