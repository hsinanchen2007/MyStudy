## 思路一：哈希
借助哈希保存节点信息。

### 代码
时间复杂度：O(n)
空间复杂度：O(n)
```cpp
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return head;
        unordered_map<Node*, Node*> ump;
        Node *cur = head;
        //1. 遍历链表，将原节点作为key，拷贝节点作为value保存在map中
        while (cur) {
            Node *copy = new Node(cur->val);
            ump[cur] = copy;                        
            cur = cur->next;
        }
        cur = head;
        //2. 复制链表next和random指针
        while (cur) {
            ump[cur]->next = ump[cur->next];
            ump[cur]->random = ump[cur->random];
            cur = cur->next;
        }
        return ump[head];
    }
};
```

## 思路二：递归

### 代码
时间复杂度：O(n)
空间复杂度：O(n)
```c++
class Solution {
public:
    Node* copyRandomList(Node* head) {        
        unordered_map<Node*, Node*> ump;
        return copy(head, ump);
    }

    Node* copy(Node *head, unordered_map<Node*, Node*> &ump) {
        if (!head) return head;
        if (ump.count(head) > 0) return ump[head];
        ump[head] = new Node(head->val);
        ump[head]->next = copy(head->next, ump);
        ump[head]->random = copy(head->random, ump);
        return ump[head];
    }
};
```

## 思路三：原地复制
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
        if (!head) return head;
        Node *cur = head;
        //1. 将复制节点添加到原节点后面
        while (cur) {
            Node *copy = new Node(cur->val);
            copy->next = cur->next;
            cur->next = copy;
            cur = copy->next;
        }
        //2. 复制random节点
        cur = head;
        while (cur) {
            if (cur->random) {
                cur->next->random = cur->random->next;
            }
            cur = cur->next->next;
        }
        //3. 分离链表
        cur = head;
        Node *newHead = head->next, *p = newHead;
        while (cur) {
            cur->next = cur->next->next;
            if (cur->next) {
                p->next = p->next->next;
            }
            cur = cur->next;
            p = p->next;
        }
        return newHead;
    }
};
```

