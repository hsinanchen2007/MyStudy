### 解题思路
此题我们要设一个虚拟头结点，主要是为了解决只有一个节点的情况；方便我们书写；

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode *pre=dummy, *latter=dummy;
        int i = 0;

        while(i <= n){
            pre = pre->next;
            ++i;
        }
        while(pre){
            pre = pre->next;
            latter = latter->next;
        }
        latter->next = latter->next->next;
        return dummy->next;
    }
};
```