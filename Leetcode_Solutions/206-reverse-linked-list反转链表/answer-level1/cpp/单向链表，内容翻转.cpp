### 解题思路

字符串翻转

定义三个指针 
前指针   pre
前期指针 cur
后指针   next

因为是单向链表, 核心逻辑
```
next = cur->next;
cur->next = pre;
pre = cur;
cur = next;
```

### 代码

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
        ListNode * pre =NULL;
        ListNode * cur = head;
        ListNode *  next = NULL;
        
        while(cur != NULL){
            next = cur->next;
            cur->next = pre;
            
            //相当于i++
            pre = cur;
            cur = next;
        }
        
        return pre;
    }
};
```