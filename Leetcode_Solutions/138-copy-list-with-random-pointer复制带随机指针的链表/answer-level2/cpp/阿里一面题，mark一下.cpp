### 解题思路
今年的面试第一题就是这道，说两种解决思路:
1. 一是unordered_map存起来,<old_node, new_node>,这样对于出现过的random节点，直接到map中查，空间复杂度为O(n);(注意一点，就是在创建第一个节点时，要把第一个节点也加进map中);
2. 二是采用新链表和旧链表相连的方法，然后将random指向旧的节点;那么random->next自然就是指向新的节点(不为空时);然后遍历将新旧链表之间解耦合，注意遍历时的条件。

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
        Node* node;
        if (NULL == head)
            return NULL;

        Node* iter = head;
        while (NULL != iter) {
            node = new Node(iter->val);
            node->next = iter->next;
            node->random = iter->random;
            iter->next = node;
            iter = node->next;
        }

        node = head->next;
        while (NULL != node) {
            // remember the condition
            if (NULL != node->random)
                node->random = node->random->next;
            // remember the condition
            if (NULL == node->next)
                break;

            node = node->next->next;
        }

        auto res = head->next;
        node = head;
        while (NULL != node->next) {
            Node* next = node->next;
            node->next = node->next->next;
            node = next;
        }

        return res;
    }
};
```