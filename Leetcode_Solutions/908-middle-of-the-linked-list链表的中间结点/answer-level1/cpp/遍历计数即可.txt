### 解题思路
1. 计数
2. 循环向后走一半位置，需要注意count为结点数量，则count/2刚好为我们所需要的结点位置；

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
    ListNode* middleNode(ListNode* head) {
        ListNode* dummy = head;
        int count = 1;
        while(head->next) {
            head = head->next;
            count++;
        } 
        count=count/2;
        while(count--){
            dummy=dummy->next;
        }
        return dummy;

    }
};
```