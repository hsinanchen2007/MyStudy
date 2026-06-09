## 思路一：哈希表
### 代码
时间复杂度：O(n)
空间复杂度：O(n)
```c++
class Solution {
public:
    bool hasCycle(ListNode *head) {
        set<ListNode*> s;
        while (head) {
            if (s.find(head) != s.end()) {
                return true;
            } else {
                s.insert(head);
                head = head->next;
            }
        }
        return false;
    }
};
```

## 思路二：快慢指针（最优解）
### 代码
时间复杂度：O(n)
空间复杂度：O(1)
```c++
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return false;
        }
        ListNode *s = head;
        ListNode *f = head->next;
        while (f->next != nullptr && f->next->next != nullptr) {
            if (f == s) {
                return true;
            } else {
                s = s->next;
                f = f->next->next;
            }
        }
        return false;
    }
};
```
#### 另一种写法
初始都从头节点开始，每次移动后判断。
```c++
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return false;
        ListNode* slow = head;
        ListNode* fast = head;        
        while (fast != nullptr && fast->next != nullptr) {            
            slow = slow->next;
            fast = fast->next->next;
            if (fast == slow) {
                return true;
            }
        }
        return false;
    }
};
```

