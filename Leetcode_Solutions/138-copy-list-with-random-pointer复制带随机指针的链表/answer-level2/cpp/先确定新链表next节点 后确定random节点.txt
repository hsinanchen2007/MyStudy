### 解题思路
1. 首先新链表的random节点可能并没有产生，故先拷贝next节点
2. 遍历新链表，根据原链表中random节点相对于头结点的距离，确定新链表节点的random节点
为了避免每次从新链表头部查找，故对原链表做Node->index的映射，对新链表做index->Node的映射

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
        Node dummy(0);
        Node* pre = &dummy, * ph = head;
        map<Node*, int> m;  // 对原链表做正向映射
        map<int, Node*> mp; // 对新链表做反向映射，便于查找random指针
        int i = 0;
        // 首先复制整条链表，除了random指针
        // 同时对节点进行编号，便于后续查找
        while (ph) {
            pre->next = new Node(ph->val);
            pre = pre->next;
            mp[i] = pre;
            m[ph] = i;
            ph = ph->next;
            ++i;
        }
        // 再次遍历，设置节点的random指针
        pre = dummy.next;
        ph = head;
        while (pre) {
            pre->random = ph->random ? mp[m[ph->random]] : nullptr;
            pre = pre->next;
            ph = ph->next;
        }
        return dummy.next;
    }
};
```