### 解题思路

**建立哨兵节点**

### 代码

```cpp
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;
        // 建立哨兵节点
        ListNode dummy(-1);
        dummy.next = head;
        ListNode* prev = &dummy;
        while(prev && prev->next){
            ListNode* slow = prev->next;
            ListNode* fast = slow->next;
            bool isFind = false;
            // 判断是否存在重复
            while(fast && fast->val == slow->val){
                fast = fast->next;
                isFind = true;
            }
            if(isFind) prev->next = fast;
            else prev = slow;
        }
        return dummy.next;
    }
};
```