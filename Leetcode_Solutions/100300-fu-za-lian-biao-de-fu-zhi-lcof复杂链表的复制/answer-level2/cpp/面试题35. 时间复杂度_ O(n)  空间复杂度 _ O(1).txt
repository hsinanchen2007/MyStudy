```cpp
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

// // 1. unordered_map<Node*, Node*>
// class Solution {
// public:
//     Node* copyRandomList(Node* head) {
       
//         if (head == NULL) 
//             return head;
//         unordered_map<Node*, Node*> map;

//         Node * p = head;
//         while (p) {
//             map[p] = new Node(p->val);
//             p = p->next;
//         }
//         p = head;
//         while (p) {
//             map[p]->next = map[p->next];
//             map[p]->random = map[p->random];
//             p = p->next;
//         }
//         return map[head];



//         ////上面的写法更简洁
//         // Node * dummyHead = new Node(0);
//         // Node * pre = dummyHead;
//         // Node * p = head;
//         // while (p) {
//         //     Node * q = new Node(p->val);
//         //     map[p] = q;
//         //     pre->next = q;
//         //     pre = q;
//         //     p = p->next;
//         // }

//         // p = head;
//         // Node * cur = dummyHead->next;
//         // while (cur && p) {
//         //     cur->random = map[p->random];
//         //     cur = cur->next;
//         //     p = p->next;
//         // }
//         // Node * ret = dummyHead->next;
//         // // delete dummyHead;
//         // return ret;

        
//     }
// };


// 2. 不用辅助空间
class Solution {
public:
    Node* copyRandomList(Node* head) {
       
        if (head == NULL) 
            return head;
        Node * p = head;
        while (p) {   // 每个节点后面插入一个值相同的节点
            Node * q = new Node (p->val);
            q->next = p->next;
            p->next = q;
            p = q->next;
        }
        p = head;
        while (p) {  // 给复制进来的节点赋random值
            p->next->random = p->random? p->random->next : NULL;
            p = p->next->next;
        }
        Node * ret = head->next;
        p = head;
        Node * q = ret;
        while ( q->next) {  // 奇数结点构成原始链表，偶数结点是新链表，返回偶数结点链表
            p->next = q->next;
            q->next = q->next->next;
            p = p->next;
            q = q->next;
        }
        p->next = NULL;  // 退出时，将原链表尾节点置为NULL
        return ret;


    }
};





```