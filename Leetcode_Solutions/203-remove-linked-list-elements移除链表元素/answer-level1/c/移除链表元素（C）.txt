**1.尾插法： 若节点值不等于val，将其尾插在链表尾部即可。**
```c
typedef struct ListNode* ptr;
struct ListNode* removeElements(struct ListNode* head, int val)
{
    ptr ans = (ptr)malloc(sizeof(struct ListNode));
    ans->next = NULL;
    ptr p = head, r = ans;
    while(p){
        if(p->val != val){
            r->next = p;
            r = p;
        }
        p = p->next;
    }
    r->next = NULL;
    return ans->next;
}
```
**2.常规做法，比较删除**
```
typedef struct ListNode* ptr;
struct ListNode* removeElements(struct ListNode* head, int val)
{
    ptr ans = (ptr)malloc(sizeof(struct ListNode));
    ans->next = head;
    ptr p = head, pre = ans, q;
    while(p){
        if(p->val == val){
            q = p;
            p = p->next;
            pre->next = p;
            free(q);
        }
        else{
            pre = p;
            p = p->next;
        }
    }
    return ans->next;
}
```