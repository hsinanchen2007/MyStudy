这个题目复杂度是 O(n)，不管你咋写，复杂度都是 O(n)，既然如此不如就写清晰一点，大家也看的明白，看的爽。上两个链表类题目必用的神器：

- `split/cut`，这两名字随便你用。它的作用是把链表头 k 个节点切下来，并返回右半部分的链表。
- `last`：返回最后一个节点。

是不是觉得太 low，太 easy，觉得 easy 就对了。如果你能在 O(1) 空间链表归并排序用上它，你就不觉得 low 了。下面是题解：

```cpp
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return nullptr;
        int len = 0;
        auto p = head;
        while (p) {
            p = p->next;
            ++len;
        }
        auto right = split(head, len - k%len);
        if (!right) return head;
        last(right)->next = head;
        return right;
    }
    
    // @->@->@->@->$
    // split(@, 3)
    // @->@->@->$, @->$
    // input: head != nullptr, 0 < k <= len(head)
    ListNode* split(ListNode* head, int k) {
        auto p = head;
        while (--k) {
            p = p->next;
        }
        auto right = p->next;
        p->next = nullptr;
        return right;
    }
    
    // @->@->@->@->$
    //          ^
    //          last
    // input: head != nullptr
    ListNode* last(ListNode* head) {
        while(head->next) {
            head = head->next;
        }
        return head;
    }
};
```

当然你也可以用代码量更少的版本（先串成环，再往后数 len-k 个节点切断），不过下面这个操作你也学不到啥东西，看看就行了。

```cpp
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return nullptr;
        auto p = head;
        int len = 1;
        while (p->next) {
            p = p->next;
            ++len;
        }
        p->next = head;
        k = len - k % len;
        while (k-->0) {
            p = p->next;
        }
        head = p->next;
        p->next = nullptr;
        return head;
    }
};
```

