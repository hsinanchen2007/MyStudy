## 思路一：双指针
### 代码
```c++
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return nullptr;
        ListNode* slow = head;
        ListNode* fast = head->next;
        bool isCycle = false;
        //1. 判断是否有环
        while (fast != nullptr && fast->next != nullptr) {
            if (fast == slow) {
                isCycle = true;
                break;
            }
            slow = slow->next;
            fast = fast->next->next;            
        }
        if (!isCycle) return nullptr;
        //2. 计算环长度，第一次相遇节点在环中，从相遇节点再次走到第二次相遇时慢指针走的步数即为环长
        int len = 0;        
        slow = slow->next;
        fast = fast->next->next;
        ++len;
        while (fast != slow) {
            slow = slow->next;
            fast = fast->next->next;
            ++len;
        }                                
        //3. 计算环入口节点，让快指针先走环长步数，然后在同时走，相遇节点即为环入口节点
        slow = head;
        fast = head;
        for (int i = 0; i < len; ++i) {
            fast = fast->next;
        }
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};
```
#### 简化代码（最优解）
1. 判断是否有环。设置快慢指针同时执行头节点，然后移动，如果相遇则存在环，否则无环。
2. 寻找环入口节点。重置快或慢节点为头结点，另一个指针为从第一次相遇节点，然后同时每次移动一步，再次相遇即为入口节点。
```c++
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return nullptr;
        ListNode* slow = head;
        ListNode* fast = head;        
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;    
            if (fast == slow) {
                fast = head;
                while (fast != slow) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return fast;
            }        
        }
        return nullptr;        
    }
};
```


## 思路二：哈希
如果第二次出现在集合中，则为入口节点。
### 代码
```c++
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return nullptr;
        unordered_set<ListNode*> uset;      
        ListNode* p = head;
        while (p != nullptr) {
            if (uset.count(p) > 0) {
                return p;
            }
            uset.insert(p);
            p = p->next;
        }
        return nullptr;        
    }
};
```
