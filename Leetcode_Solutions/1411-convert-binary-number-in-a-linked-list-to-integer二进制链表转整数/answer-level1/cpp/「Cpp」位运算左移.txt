### 解题思路

**先**左移一位，**后**加上当前节点的值。**不是**先加后移。

```cpp
class Solution {
public:
    int getDecimalValue(ListNode* head) {

        int ret = 0;
        while ( head != NULL){
            ret <<= 1;
            ret += head->val;
            head = head->next;
        }
        return ret;

    }
};
```