方法1：
![leetcode.png](https://pic.leetcode-cn.com/ddb2e5db1c2b59d2cc2ece0805214350cee65588cb478b4e905ca65dd6432ffe-leetcode.png)

```
struct ListNode* removeElements(struct ListNode* head, int val){
    struct ListNode *p = (struct ListNode*)malloc(sizeof(struct ListNode)), *q = head, *newHead;
    p -> next = head;
    newHead = p;
    while (q){
        if (q -> val == val)
            p -> next = q -> next;
        else
            p = p -> next; 
        q = q -> next;
    }
    p -> next = NULL;
    return newHead -> next;
}
```
