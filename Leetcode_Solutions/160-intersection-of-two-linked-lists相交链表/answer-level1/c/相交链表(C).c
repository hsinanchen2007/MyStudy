**1.长链表先遍历到和短链表长度相同，然后一起开始遍历，直到找到交点为止。**

```c

typedef struct ListNode* NodePtr;
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    if(!headA && !headB){
        return NULL;
    }
    int alen = 0, blen = 0, delta;
    NodePtr p = headA;
    NodePtr q = headB;
    while(p){
        alen++;
        p = p->next;
    }
    while(q){
        blen++;
        q = q->next;
    }
    if(alen > blen){
        delta = alen - blen;
        p = headA;
        while(delta){
            p = p->next;
            delta--;
        }
        q = headB;
    }
    else{
        delta = blen - alen;
        p = headB;
        while(delta){
            p = p->next;
            delta--;
        }
        q = headA;
    }
    while(p != q){
        p = p->next;
        q = q->next;
    }
    return p;
}
```
**2.先将一个链表中的节点存入set中，然后遍历另一个链表，若能在set中找到相同节点，返回即可。**
```
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *p = headA, *q = headB;
        unordered_set<ListNode*> s;
        while(p){
            s.insert(p);
            p = p->next;
        }
        while(q){
            if(s.find(q) != s.end())
                return q;
            q = q->next;
        }
        return nullptr;
    }
};
```
**3.双指针法**
```
typedef struct ListNode* NodePtr;
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    NodePtr p = headA;
    NodePtr q = headB;
    while(p != q){
        p = (p == NULL) ? headB : p->next;
        q = (q == NULL) ? headA : q->next;
    }
    return p;
}
```