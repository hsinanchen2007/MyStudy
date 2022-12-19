### 解题思路


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
        Node* node = head;
        stack<Node*> st1;
        while(node)
        {
            if(node->child != NULL)
            {
                st1.push(node->next);
                node->next = node->child;
                node->child->prev = node;
                node->child = NULL;
            }
            else if(node->next == NULL && !st1.empty())
            {
                Node* nxt = st1.top();
                st1.pop();
                node->next = nxt;
                if(node && nxt)
                    nxt->prev = node;
            }
                node = node->next;
        }
        return head;
    }
};
```