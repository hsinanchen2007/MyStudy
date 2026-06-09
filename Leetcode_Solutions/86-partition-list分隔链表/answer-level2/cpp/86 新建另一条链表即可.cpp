### 解题思路
新建另一条链表，遍历两遍原有链表即可

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
    ListNode* partition(ListNode* head, int x) {
        ListNode* pre = new ListNode(-1);
        ListNode* res = pre; 
        ListNode* old = head;
        while(old){
            int val = old->val;
            if(val < x){
                ListNode* new_node = new ListNode(val);
                pre->next = new_node;
                pre = pre->next;
            }
            old = old->next;
        }
        old = head;
        while(old){
            int val = old->val;
            if(val >= x){
                ListNode* new_node = new ListNode(val);
                pre->next = new_node;
                pre = pre->next;
            }
            old = old->next;
        }
        return res->next;
    }
};
```

### 结果
执行用时 : 4 ms , 在所有 C++ 提交中击败了 92.34% 的用户 
内存消耗 : 6.9 MB , 在所有 C++ 提交中击败了 100.00% 的用户