### 解题思路
之前的代码在while里面计算next1和next2，如下：
```cpp
        while (cur->next != NULL) {
          ListNode* next1 = cur->next;
          ListNode* next2 = next1->next;
```
然后发现每次进入while可以重复使用next2，优化后稳定在4-8ms

### 代码

```cpp
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode temp(0);
        temp.next = head;

        ListNode* cur = &temp;
        ListNode *next1;
        ListNode *next2 = cur->next;
        while (cur->next != NULL) {
          next1 = next2;
          next2 = next1->next;
          if (next2 != NULL && next1->val == next2->val) {
            while (next2->next != NULL && next2->val == next2->next->val) {
              next2 = next2->next;
            }
            next2 = next2->next;
            cur->next = next2;
          } else {
            cur = next1;
          }
        }
        return temp.next;
    }
};
```