### 解题思路
使用map保存对应关系，然后设置next和random节点

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
        if (head == NULL) return NULL;
        unordered_map<Node*, Node*> mmap;

        Node *p = head;
        while (p != NULL) {
            mmap[p] = new Node(p->val);
            p = p->next;
        }
        p = head;
        while (p != NULL) {
            mmap[p]->next = mmap[p->next];
            mmap[p]->random = mmap[p->random];
            p = p->next;
        }
        return mmap[head];
    }
};
```