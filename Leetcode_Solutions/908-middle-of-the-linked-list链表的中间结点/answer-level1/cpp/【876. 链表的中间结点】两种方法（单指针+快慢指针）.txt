## 思路一：单指针
先统计节点个数，然后从头开始走一半。

### 代码
时间复杂度：O(n)
空间复杂度：O(1)
```cpp
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *p = head;
        int cnt = 0;
        while (p) {
            ++cnt;
            p = p->next;
        }
        p = head;
        cnt /= 2;
        while (cnt) {
            p = p->next;
            --cnt;
        }
        return p;        
    }
};
```

## 思路二：快慢指针

### 代码
时间复杂度：O(n)
空间复杂度：O(1)
```c++
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *fast = head, *slow = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }    
        return slow;        
    }
};
```
