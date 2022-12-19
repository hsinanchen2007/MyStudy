## 方法一：迭代（逐级展开）

- 执行用时 :8 ms, 在所有 C++ 提交中击败了60.59%的用户
- 内存消耗 :7.4 MB, 在所有 C++ 提交中击败了100.00%的用户

找到一条**子链**，就把**子链的主链**接到**原来的主链**上，不管子链本身有没有子链。

```
1->2->3->4->5->6（原来的主链）
      |
      7->8->9->10（子链的主链）
         |
         11->12（子链的子链）
```

```
1->2->3->7->8->9->10->4->5->6
            |
            11->12
```

```
1->2->3->7->8->11->12->9->10->4->5->6
```

```c++
class Solution {
public:
    Node* flatten(Node* head) {
        if (!head) {
            return head;
        }
        for (Node* p = head; p; p = p->next) {
            if (p->child) {
                Node* q = p->child;
                for (; q->next; q = q->next) {}
                q->next = p->next;
                if (p->next) {
                    p->next->prev = q;
                }
                p->next = p->child;
                p->child->prev = p;
                p->child = nullptr;
            }
        }
        return head;
    }
};
```

## 方法二：递归

- 执行用时 :8 ms, 在所有 C++ 提交中击败了60.59%的用户
- 内存消耗 :7.4 MB, 在所有 C++ 提交中击败了100.00%的用户

```c++
class Solution {
public:
    Node* merge(Node* head) {
        Node* p = nullptr;
        Node* q = nullptr;
        for (p = head->child; p; p = p->next) {
            if (p->child) {
                p = merge(p);
            }
            q = p;
        }
        q->next = head->next;
        if (head->next) {
            head->next->prev = q;
        }
        head->next = head->child;
        head->child->prev = head;
        head->child = nullptr;
        return q;
    }
    
    Node* flatten(Node* head) {
        if (!head) {
            return head;
        }
        for (Node* p = head; p; p = p->next) {
            if (p->child) {
                p = merge(p);
            }
        }
        return head;
    }
};
```

