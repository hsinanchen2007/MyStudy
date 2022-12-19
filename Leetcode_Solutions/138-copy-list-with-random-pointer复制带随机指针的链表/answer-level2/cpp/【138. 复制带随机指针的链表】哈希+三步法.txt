## 思路一：哈希
借助哈希保存节点信息。

### 代码
时间复杂度：O(n)
空间复杂度：O(n)
```c++
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) {
            return head;
        }
        Node *cur = head;
        unordered_map<Node*, Node*> ump;
        //1. 遍历链表，将原节点作为key，拷贝节点作为value保存在map中
        while (cur != nullptr) {
            Node *copy = new Node(cur->val);
            ump[cur] = copy;
            cur = cur->next;
        }
        //2. 复制链表next和random指针
        cur = head;
        while (cur != nullptr) {
            ump[cur]->next = ump[cur->next];
            ump[cur]->random = ump[cur->random];
            cur = cur->next;
        }
        return ump[head];
    }
};
```

## 思路二：原地复制
1. 复制节点，同时将复制节点链接到原节点后面，如A->B->C 变为 A->A'->B->B'->C->C'。
2. 设置节点random值。
3. 将复制链表从原链表分离。

### 代码
时间复杂度：O(n)
空间复杂度：O(1)
```c++
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) {
            return head;
        }
        Node *node = head;
        //1. 将复制节点添加到原节点后面
        while (node != nullptr) {
            Node *copy = new Node(node->val, nullptr, nullptr);
            copy->next = node->next;
            node->next = copy;
            node = copy->next;
        }
        
        //2. 复制random节点
        node = head;
        while (node != nullptr) {
            if (node->random != nullptr) {
                node->next->random = node->random->next;
            }            
            node = node->next->next;
        }
        
        //3. 分离链表
        node = head;
        Node *newHead = head->next;
        Node *newNode = newHead;
        while (node != nullptr) {
            node->next = node->next->next;     
            if (newNode->next != nullptr) {
                newNode->next = newNode->next->next;            
            }            
            node = node->next;
            newNode = newNode->next;
        }
        return newHead;
    }
};
```
