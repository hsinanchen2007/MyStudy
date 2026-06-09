### 解题思路
深度拷贝，所以还是必须得有一个存储映射关系的载体，选择 map，好用省心

### 代码

```cpp
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
        Node *dummy = new Node(0, 0, 0);
        Node *cur = dummy;
        Node *it = head;
        map<Node *, Node *> table;
        int cnt = 0;
        
        while (it) {
            Node *node = new Node(it->val, 0, 0);
            table[it] = node;
            cur->next = node;
            cur = node;
            it = it->next;
        }
        
        it = head;
        cur = dummy->next;
        cnt = 0;
        while (it) {
            if (it->random)
                cur->random = table[it->random];
            it = it->next;
            cur = cur->next;
            cnt++;
        }
        
        Node *res = dummy->next;
        delete dummy;
        
        return res;
    }
};
```