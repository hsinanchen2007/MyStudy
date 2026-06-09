### 解题思路
所有提交中，执行时间两极分化哈，应该是用栈和递归的差距
掌握了栈的使用，很多时候比递归感觉更直观（从自己的角度）
需要链表插入操作的时候，一个哑节点是“居家旅行必备良品”

### 代码

```cpp
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/
class Solution {
public:
    Node* flatten(Node* head) {
        Node *dummy = new Node(0);
        stack<Node *> back;
        Node *cur = dummy;
        Node *it = head;
        
        while (true) {
            if (it == NULL) {
                if (back.empty())
                    break;
                it = back.top();     
                back.pop();
            }
            Node *node = new Node(it->val);
            node->prev = cur;
            cur->next = node;
            cur = node;
            if (it->next)
                back.push(it->next);
            it = it->child;
        }
        
        Node *res = dummy->next;
        delete dummy;
        if (res)
            res->prev = NULL;
        
        return res;
    }
};
```