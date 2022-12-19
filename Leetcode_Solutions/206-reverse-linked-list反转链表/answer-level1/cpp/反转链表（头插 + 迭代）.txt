## 方法一： 遍历，头插

思路：遍历链表，从第二个结点起，摘下每个结点，之后头插到原始链表中

```cpp
      ListNode *reverseList(ListNode *head) {
        if (!head){
            return nullptr;
        }
        ListNode *p, *r;
        p = head->next;
        head->next = nullptr;
        while (p != nullptr) {
            r = p->next;
            p->next = head;
            head = p;
            p = r;
        }
        return head;
    }
```

## 方法二：迭代，改变前后结点指针指向

思路：遍历链表，cur为遍历当前结点，pre为其前驱结点，r后其后继结点。让cur结点的next域指向pre结点，注意到一旦调整指针指向后，cur的后继结点就会断开，为此需要用r来指向原cur的后继节点。

```cpp
    ListNode *reverseList(ListNode *head) {
        ListNode *pre = nullptr, *cur = head, *r = nullptr;
        while (cur != nullptr) {
            r = cur->next;
            cur->next = pre;
            pre = cur;
            cur = r;
        }
        return pre;
    }
```