### 解题思路
此处撰写解题思路
执行用时击败99.07%，内存消耗击败100.00%
![2020-01-09_000706.png](https://pic.leetcode-cn.com/d9c753250545b8e323321cc5e12764ed98486b72f80ce11ab1c507f064a9a423-2020-01-09_000706.png)

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
        if(!head)
            return head;
        Node *p=new Node;
        Node *tail=p,*h=head;
        tail->prev=nullptr;
        tail->next=nullptr;
        tail->child=nullptr;
        tail->val=head->val;

        if(h->child)
        {
            Node *t = flatten(h->child);
            t->prev=tail;
            tail->next = t;
            if(!h->next)
                return p;
             while(t->next)
            {
                t=t->next;
            }
            tail=t;//尾插法，tail必须指向尾指针
            
            
        }
        if(h->next)
        {
            
            Node *t = flatten(h->next);
            t->prev=tail;
            tail->next=t;
            //这里不需要了，当前链表的后序结点，tail无需指向尾指针。
            //因为递归到最后一层，后面不用插入新结点了，直接返回上一层即可。
            //while(t&&t->next)
            //{
            //    t=t->next;
            //}
            //tail=t;
        }
        return p;
    }
};
```