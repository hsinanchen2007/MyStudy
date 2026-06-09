### 解题思路
主要是递归，递归基的两种情况就是剩一个，一个都不剩，这里用了或运算的性质保证了指针非空合法性

### 代码

```cpp

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head||!head->next){
            return head;
        }else{
            ListNode * next = head->next;
            ListNode * next_next = next->next;
            next->next=head;
            head->next=swapPairs(next_next);
            return next;
        }
    }
};
```