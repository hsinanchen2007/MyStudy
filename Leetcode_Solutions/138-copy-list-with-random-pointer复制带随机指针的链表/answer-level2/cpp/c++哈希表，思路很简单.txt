### 解题思路
先遍历一次链表，复制每个节点，再遍历一次，复制节点的两个指针

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
    Node* copyRandomList(Node* head) 
    {
        if(!head) return NULL;
        unordered_map<Node*, Node*> m;
        Node* cur = head;
        Node* pre = head;
        while(cur)
        {
            Node* clone = new Node(cur -> val);
            m[cur] = clone;
            cur = cur -> next;
        }
        while(pre)
        {
            m[pre] -> next = m[pre -> next];
            m[pre] -> random = m[pre -> random];
            pre = pre -> next;
        }
        return m[head];
    }
};

```