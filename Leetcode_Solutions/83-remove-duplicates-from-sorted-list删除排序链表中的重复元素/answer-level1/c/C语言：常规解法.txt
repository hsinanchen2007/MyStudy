

慢一点的：

```
struct ListNode* deleteDuplicates(struct ListNode* head){
    struct ListNode *p = head, *q;
    while (p){
        q = p -> next;
        while (q){
            if (q -> val == p -> val){
                p -> next = q -> next;
            }
            q = q -> next;
        }
        p = p -> next;
    }
    return head;
}

```

快一点的：

```
struct ListNode* deleteDuplicates(struct ListNode* head){
    struct ListNode *p = head;
    while (p && p -> next){
        if (p -> next -> val == p -> val){
            p -> next = p -> next -> next;
        }
        else{
            p = p -> next;
        }
    }
    return head;
}
```
更快一点的：

```
struct ListNode* deleteDuplicates(struct ListNode* head){
    struct ListNode *p = head;
    int cnt = 0;

    if (head == NULL)
        return NULL;
    while (p){
        p = p -> next;
        cnt++;
    }
    struct ListNode *q = (struct ListNode*)malloc(sizeof(struct ListNode) * cnt), *r = head, *res;
    q -> val = head -> val;
    res = q;
    while (r){
        if (r -> val != q -> val){
            q -> next = r;
            q = q -> next;
        }
        r = r -> next;
    }
    q -> next = NULL;
    return res;
}
```
PS：对于[1,2,1,2]，方法1和3输出是[1,2],
方法2输出则是[1,2,1,2],但它们都对，可能没有这样的测试用例。
