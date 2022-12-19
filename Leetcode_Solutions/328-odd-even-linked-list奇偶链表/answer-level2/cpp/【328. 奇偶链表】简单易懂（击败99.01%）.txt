## 思路
设置两个指针，分别指向奇数节点和偶数节点，然后将链表按奇偶分离。

### 代码
时间复杂度：O(n)
空间复杂度：O(1)
```c++
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode *odd = head;
        ListNode *sEven = head->next;
        ListNode *even = head->next;
        while (even != nullptr && even->next != nullptr) {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = sEven;
        return head;
    }
};
```
