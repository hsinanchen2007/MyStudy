### 解题思路
用map保存当前node 和复制链表的node对应关系

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
        if (head == NULL) {
            return NULL;
        }       
        Node* node = head;
        Node* dummy = new Node(-1);
        Node* pre = dummy;
        map<Node*, Node*> m_NodeMap;

        while(node != NULL) {
            Node* tmp = new Node(node->val);
            m_NodeMap.insert(make_pair(node, tmp));
            pre->next = tmp;
            pre = tmp;
            node = node->next;
        }

        node = head;
        while(node != NULL) {
            //auto iter = m_NodeMap.find(node);
            m_NodeMap[node]->random = m_NodeMap[node->random];
            node =node->next;
        }
        return dummy->next;
    }
};
```