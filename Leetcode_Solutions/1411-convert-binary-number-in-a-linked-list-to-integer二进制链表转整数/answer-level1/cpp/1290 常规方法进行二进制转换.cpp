时间复杂度O(n)，空间复杂度O(1)
### 代码

```cpp
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int ans = 0;
        while (head) {
            ans = ans*2+(head->val);
            head = head->next;
        }
        return ans;
    }
};
```