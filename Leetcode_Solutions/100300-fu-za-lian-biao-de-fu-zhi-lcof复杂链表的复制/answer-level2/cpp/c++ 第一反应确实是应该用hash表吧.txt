### 解题思路
先遍历一遍复制没有random指针的链表，这个时候原表和现在的表节点的对应关系已经有了 我们用hashmap记录一下
再遍历一遍 每个位置读取random指向的原表节点，根据hashmap查到复制后对应的节点，建立连接即可

就是最快的了！

欢迎大家关注我的leetcode仓库～
[我的题解](https://www.github.com/wfnuser/leetcode)
[我的github](https://www.github.com/wfnuser)
最近沉迷刷题 同时也在学习和实现lua，欢迎交流


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
        if (head == NULL) return head;
        
        unordered_map<Node*, Node*> rnd;

        Node* fakeHead = new Node(head->val);

        Node* p = head;
        Node* fp = fakeHead;

        while(p != NULL) {
            rnd[p] = fp;
            p = p->next;
            if (p == NULL) fp->next = NULL;
            else {
                Node* next = new Node(p->val);
                fp->next = next;
            }
            fp = fp->next;
        }

        p = head;
        fp = fakeHead;
        while(p != NULL) {
            fp->random = rnd[p->random];
            p = p->next;
            fp = fp->next;
        }

        return fakeHead;
    }
};
```