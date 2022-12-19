### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* startp = head;
        ListNode* endp = head;
        ListNode fakeh(-1);
        fakeh.next = head;
        ListNode* pointer = &fakeh;
        stack<ListNode*> msk;
        for (int i = 0; i <= n; i++) {
            if (i == m - 1) startp = pointer;
            if (i >= m)msk.push(pointer);
            
            pointer = pointer->next;
            if (i == n) {
                endp = pointer;
                while (!msk.empty()) {
                    startp->next = msk.top();
                    msk.pop();
                    startp = startp->next;
                }
                startp->next = endp;
            }
        }
        head = fakeh.next;
        return head;


    }
};
```