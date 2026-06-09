### 解题思路
先遍历一遍计算总数，然后遍历到中间
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
        ListNode* swap = head;
        int count = 1;
        while(swap->next != NULL){
            count++;
            swap = swap->next;
        }
        int i = 0;
        while(i != count/2){
            head = head->next;
            i++;
        }
        return head;
    }
};
```