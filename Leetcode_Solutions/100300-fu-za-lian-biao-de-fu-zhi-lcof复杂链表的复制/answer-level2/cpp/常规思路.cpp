### 解题思路
    第一遍遍历，建立节点，给next赋值，构造完整的新链表
    第二遍遍历，不断给random赋值，由于val有重复，因此，
        使用 head->random 距离 第一个节点的距离（个数），作为绝对条件，
        在新链表对应节点 p，也找到对应距离的那个节点 pTmp，赋给 p->random  

### 代码

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
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)   return head;
        Node* newHead = new Node(-1);
        Node* p = newHead;
        Node* q = head;
        while(q){
            Node* node = new Node(q->val);
            p->next = node; 
            q = q->next;
            p = p->next;
        }
        p = newHead->next;
        q = head;
        Node* pTmp = newHead->next;
        Node* qTmp = head;
        while(q){
            if(q->random == NULL){
                p->random = NULL;
            }else{
                int n = 0;
                pTmp = newHead->next;
                qTmp = head;
                while(qTmp != q->random){
                    qTmp = qTmp->next;
                    ++n;
                }
                while(n > 0){
                     pTmp = pTmp->next;
                     --n;
                }
                p->random = pTmp;
            }
            q = q->next;
            p = p->next;
        }
        return newHead->next;
    }
};










```