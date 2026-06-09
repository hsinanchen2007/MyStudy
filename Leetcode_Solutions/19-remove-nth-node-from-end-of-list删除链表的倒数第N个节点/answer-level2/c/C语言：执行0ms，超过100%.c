![双指针.png](https://pic.leetcode-cn.com/ee83ac2c92dc152263b188f9f2022a78e9e7f3dab8651d0b80afbe53b2562010-%E5%8F%8C%E6%8C%87%E9%92%88.png)
方法1：双指针
```
struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode *p, *q;
    p = q = head;
    n++;
    while (n-- && q)
        q = q -> next;
    if (n == 0)//要删除的是首结点
        return head -> next;
    while (q){
        p = p -> next;
        q = q -> next;
    }
    p -> next = p -> next -> next;
    return head;
}

```
或者这样，同样执行0ms，超过100%
```
struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode *new = (struct ListNode*)malloc(sizeof(struct ListNode)), *p, *q;
    new -> next = head;
    p = q = new;
    while (n--)
        q = q -> next;
    while (q -> next){
        p = p -> next;
        q = q -> next;
    }
    p -> next = p -> next -> next;
    return new -> next;
}
```

方法2：常规思路，效率减半
```
struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode *p = head, *q;
    int cnt = 0;
    while (p){
        p = p -> next;
        cnt++;
    }
    cnt -= n;
    if (cnt == 0)//要删除的是首结点时，如[1] 1, [1,2] 2
        return head -> next;
    p = head;
    while (--cnt)
        p = p -> next;
    q = p -> next;
    p -> next = q -> next;
    free(q);
    return head;
}
```


