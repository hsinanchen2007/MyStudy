## 思路一：移动尾节点到头节点
算法：
1. 计算链表长度，对于移动距离进行模运算（k > 链表长度）
2. 循环移动次数，每次将尾节点移到头节点前并重新设置头节点。
### 代码
```c++
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        int len = 0;
        ListNode *node = head;
        while (node != nullptr) {
            node = node->next;
            ++len;
        }
        k %= len;
        for (int i = 0; i < k; ++i) {
            ListNode *pre = head;            
            node = head;
            while (node->next != nullptr) {
                pre = node;
                node = node->next;
            }
            node->next = head;//尾结点插入头节点前
            head = node;//重新设置头节点
            pre->next = nullptr;
        }
        return head;
    }
};
```

## 思路二：闭合链表然后断开
1. 将链表闭合为环，同时计算链表长度。
2. 找到相应位置断开环，重新确定链表尾和头。
### 代码
时间复杂度：O(n)
```c++
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        int len = 0;
        ListNode *node = head;
        ListNode *pre = nullptr;
        while (node != nullptr) {
            pre = node;
            node = node->next;
            ++len;
        }
        pre->next = head;//闭合链表
        k %= len;
        node = head;
        pre = nullptr;
        //2. 断开位置为从头开始第len - k位置
        for (int i = 0; i < len - k; ++i) {
            pre = node;
            node = node->next;
        }
        head = node;
        pre->next = nullptr;
        return head;
    }
};
```
#### 简化代码
```c++
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        int len = 1;
        ListNode *node = head;        
        while (node->next != nullptr) {            
            node = node->next;
            ++len;
        }
        node->next = head;
        k %= len;
        node = head;
        ListNode *pre = nullptr;
        for (int i = 0; i < len - k; ++i) {
            pre = node;
            node = node->next;
        }
        head = node;
        pre->next = nullptr;
        return head;
    }
};
```


