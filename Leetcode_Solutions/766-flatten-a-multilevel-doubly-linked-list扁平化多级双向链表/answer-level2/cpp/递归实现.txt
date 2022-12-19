### 解题思路

参考用户[@heaven_devils](/u/heaven_devils/)的[实现](https://leetcode-cn.com/problems/flatten-a-multilevel-doubly-linked-list/solution/cdi-gui-by-heaven_devils/)。个人觉得非常不错

- 定义一个函数helper，该功能是将以head为头节点的链表**扁平化**，并返回**最后一个节点**。
- 那么最后一个节点到底是什么节点？考虑这样一个事实：假如一个节点的`next`和`child`同时不为空，那么扁平化之后`next`是接在`child`之后的。所以假如`next`不为空，那么就返回**父链**的最后一个节点;否则返回它的**子链**`child`的最后一个节点。
- 上面描述之后，递归出口也很明显了，当一个节点`head`的`head->next`和`head->child`同时为空的时候，它就是一个结尾节点。而且假如递归输入head为空直接返回。

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


    Node* helper(Node *head){
        
        if(head ==nullptr || (head->next == nullptr && head->child == nullptr)) return head;
        Node *_next = head->next;
        // 如果有child节点，则将其扁平化
        Node *last = helper(head->child);
        if(last){
            head->next = head->child;
            head->child->prev = head;
            last->next = _next;
            if(_next) _next->prev = last;
            head->child = nullptr;
        }
        // 返回最后一个节点,最后一个节点的特点：没有next也没有child
        return _next ? helper(_next) : last;
    }
    Node* flatten(Node* head) {
        helper(head);
        return head;      
    }
};
```