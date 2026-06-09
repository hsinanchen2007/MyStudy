### 解题思路
需要三个指针，一个指向pre数值的最后一个，一个指向当前数值第一个，一个往后找，找到与当前数值不同则进行删或不做修改。

### 代码

```cpp
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr)return head;
        ListNode *result = head;
        ListNode *l = head, *r = head;
        ListNode* pre = nullptr;
        int count = 0;
        while (1) {
            if (r->next == nullptr) {
                if (r != l) {
                    if (pre != nullptr)
                        pre->next = nullptr;
                    else return nullptr;
                }
                break;
            }
            else {
                r = r->next;
                if (r->val != l->val && count > 0) {
                    if (pre != nullptr)
                        pre->next = r;
                    else result = r;
                    l = r;
                    count = 0;
                }
                else if (r->val != l->val && count == 0) {
                    pre = l;
                    l = r;
                }
                else {
                    count++;
                }
            }
        }
        return result;
    }
};
```