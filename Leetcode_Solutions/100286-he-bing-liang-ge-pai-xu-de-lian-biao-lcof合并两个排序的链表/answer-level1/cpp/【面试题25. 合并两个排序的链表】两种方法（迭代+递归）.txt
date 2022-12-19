## 思路一：迭代
添加一个虚拟节点处理头结点。

### 代码
时间复杂度：O(m + n)
空间复杂度：O(1)
```cpp
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1 || !l2) return l1 ? l1 : l2;
        ListNode *newHead = new ListNode(-1), *pre = newHead;                
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                pre->next = l1;
                l1 = l1->next;
            } else {
                pre->next = l2;
                l2 = l2->next;
            }
            pre = pre->next;
        }
        pre->next = l1 ? l1 : l2;
        return newHead->next;
        
    }
};
```

## 思路二：递归

### 代码
时间复杂度：O(m + n)
空间复杂度：O(1)
```cpp
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1 || !l2) return l1 ? l1 : l2;
        ListNode *newHead = nullptr;                
        if (l1->val <= l2->val) {
            newHead = l1;
            newHead->next = mergeTwoLists(l1->next, l2);
        } else {
            newHead = l2;
            newHead->next = mergeTwoLists(l1, l2->next);
        }
        return newHead;        
    }
};
```
