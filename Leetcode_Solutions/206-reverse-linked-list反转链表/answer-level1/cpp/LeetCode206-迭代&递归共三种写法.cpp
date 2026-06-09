#### 迭代
```cpp
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *cur = head, *prev = nullptr;
        while (cur) {
            ListNode *ne = cur->next;
            cur->next = prev;
            prev = cur;
            cur = ne;
        }
        return prev;
    }
};
```

#### 递归代码1

比较好理解

```java
class Solution {
public:
    // 返回完成翻转的头结点，和尾结点
    pair<ListNode*, ListNode*> dfs(ListNode *cur) {
        if (!cur->next) {
            return {cur, cur};
        }
        auto t = dfs(cur->next);
        ListNode *root= t.first, *tail = t.second;
        tail->next = cur;
        cur->next = nullptr;
        return {root, cur};
    }
    
    ListNode* reverseList(ListNode* head) {
        if (!head) return nullptr;
        // 1-> 2-> 3-> <-4 <-5 <-6
        return dfs(head).first;
    }
};
```

#### 递归代码2

优化递归代码1

```cpp
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *root = reverseList(head->next);
        ListNode *tail = head->next;
        tail->next = head;
        head->next = nullptr;
        return root;
    }
};
```