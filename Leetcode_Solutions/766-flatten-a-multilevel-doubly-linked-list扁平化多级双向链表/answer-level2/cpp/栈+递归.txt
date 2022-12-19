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
            stack<Node*> nodeStack;

    Node*  p = head, *prev = NULL;
    while(p) {
        if (p->child) {
            if (p->next) {
                Node* q = p->next;
                nodeStack.push(q);
            }

            p->next = p->child;
            p->child->prev = p;
            p->child = NULL;
            prev = p;
            p = p->next;
        } else {
            prev = p;
            p = p->next;
        }
    }

    while(!nodeStack.empty()) {
        Node* topNode = nodeStack.top();
        nodeStack.pop();

        Node* flattenSub = flatten(topNode);
        prev->next = flattenSub;
        flattenSub->prev = prev;
        p = prev;
        while(p) {
            prev = p;
            p = prev->next;
        }
    }

    return head;
    }
};
```

![430.png](https://pic.leetcode-cn.com/e18f58b67c410f709fda43e258ec94e6af87d4eac1c9fff75d2b733d576253e8-430.png)
