### 解题思路
1.建立一个映射表，原链表每一个结点和复制结点一一映射
2.遍历映射表，建立复制结点之间的关系

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
        if (head == nullptr) {
            return nullptr;
        }
         map<Node*, Node*> oddNewMap;

        // 建立一个原结点和新结点的映射表
        for (Node *i = head; i != nullptr; i = i->next) {
            Node *copyNode = new Node(i->val);
            oddNewMap.insert(pair<Node*, Node*>(i, copyNode));
        }

        Node *copyHead = oddNewMap.find(head)->second;
        // 拷贝next指针区域
        for (auto it = oddNewMap.begin(); it != oddNewMap.end(); it++) {
            Node *copyNode = it->second;

            if (oddNewMap.find(it->first->next) != oddNewMap.end()) {
                copyNode->next = oddNewMap.find(it->first->next)->second;
            }
            if (oddNewMap.find(it->first->random) != oddNewMap.end()) {
                copyNode->random = oddNewMap.find(it->first->random)->second;
            }
        }

        return copyHead;
    }
};
```