### 解题思路一

哈希表 + 递归

### 代码一

```cpp
class Solution {
private:
    unordered_map<Node *, Node *> dict;
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr)
            return nullptr;         
        if(dict.count(head) > 0)
            return dict[head];
        Node *newHead = new Node(head->val);
        dict.emplace(head, newHead);
        newHead->next = copyRandomList(head->next);
        newHead->random = copyRandomList(head->random);
        return newHead;
    }
};
```

### 解题思路二

哈希表 + 迭代

### 代码二

```cpp
class Solution {
private:
    unordered_map<Node *, Node *> dict;
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr)
            return nullptr;         
        
        Node *newHead = cloneNode(head);
        Node *p = newHead;
        while(head != nullptr) {
            p->next = cloneNode(head->next);
            p->random = cloneNode(head->random);
            head = head->next;
            p = p->next;
        }
        
        return newHead;
    }
    
    Node* cloneNode(Node* old) {
        if(old == nullptr)
            return nullptr;
        if(dict.count(old) > 0)
            return dict[old];
        Node *newNode = new Node(old->val);
        dict.emplace(old, newNode);
        return newNode;
    }
};
```



### 解题思路三

1. 生成镜像列表，先遍历链表，复制出一个新老节点相间的链表；
2. 再遍历一次，复制random指针，利用镜像列表的特点；
3. 拆分链表。

### 代码三

```cpp

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr)
            return nullptr;         
        
        Node *p = head;
        Node *newNode;
        while(p) {
            newNode = new Node(p->val);
            newNode->next = p->next;
            p->next = newNode;
            p = newNode->next;
        }
        
        p = head;
        Node *newHead, *q;
        newHead = q = head->next;  // head != nullptr
        while(p) {
            q->random = p->random ? p->random->next : nullptr;
            p = q->next;
            q = p ? p->next: nullptr;
        }
        
        p = head;
        q = head->next;
        while(p) {
            p->next = q->next;
            p = p->next;
            q->next = p ? p->next : nullptr;
            q = q->next;
        }
        
        return newHead;
    }
};
```