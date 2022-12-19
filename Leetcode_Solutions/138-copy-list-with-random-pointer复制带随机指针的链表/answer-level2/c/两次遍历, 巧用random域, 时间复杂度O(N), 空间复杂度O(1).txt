1. 遍历远链表, 逐节点创建新链表, 新链表ramdom值COPY原链表的, 原链表random值更新为新链表节点的地址
2. 遍历新链表, 逐个更新random值为random->random
两次遍历, 时间复杂度O(N), 空间复杂度O(1)

```
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return head;
        Node *p = head;
        Node dummyHead, *tail;
        tail = &dummyHead;
        while(p){
            tail->next = new Node(0);
            tail = tail->next;
            memcpy(tail, p, sizeof(Node));
            p->random = tail;
            p = p->next;
        }
        tail = dummyHead.next;
        while(tail){
            if(tail->random)
                tail->random = tail->random->random;
            tail = tail->next;
        }
        return dummyHead.next;
    }
};
```
