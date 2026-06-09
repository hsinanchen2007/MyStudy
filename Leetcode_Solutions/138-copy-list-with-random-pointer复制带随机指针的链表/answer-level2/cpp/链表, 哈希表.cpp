哈希表
```
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr) return head;
        //HashMap
        Node* curr = head;
        unordered_map<Node*, Node*> ump;
        //1. 遍历链表，将原节点作为key，拷贝节点作为value保存在map中
        while(curr != nullptr){
            Node* temp = new Node(curr->val);
            ump[curr] = temp;
            curr = curr->next;
        }
        //2. 复制链表next和random指针
        curr = head;
        while(curr != nullptr){
            ump[curr]->next = ump[curr->next];
            ump[curr]->random = ump[curr->random];
            curr = curr->next;
        }
        return ump[head];
    }
};
```
原地复制链表法
```
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr) return head;
        copyNext(head);
        copyRandom(head);
        return splitList(head);
    }
    //1
    void copyNext(Node* head){
        Node* curr = head;
        while(curr != nullptr){
            Node* temp = new Node(curr->val, nullptr, nullptr);
            //将复制节点添加到原节点
            temp->random = curr->random;
            temp->next = curr->next;
            curr->next = temp;
            //更新curr为原链表的下一节点
            curr = curr->next->next;
        }
    }        
    //2复制random节点
    void copyRandom(Node* head){        
        while(head != nullptr){
            if(head->next->random != nullptr){
                head->next->random = head->random->next;
            }            
            head = head->next->next;
        }
    }

    //3.复制的节点分离出来
    Node* splitList(Node* head){
        Node* newHead = head->next;
        while(head != nullptr){
            //将copy的链表与原链表分开
            Node* temp = head->next;
            head->next = temp->next;
            head = head->next;
            if(temp->next != nullptr){
                temp->next = temp->next->next;
            }
        }
        return newHead;
    }   
};

```
