### 解题思路
此处撰写解题思路

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
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode* p1 = head;
        ListNode* p2 = head;
        while(p1){
            if(k > 0){
                p1 = p1 -> next;
                k--;
            }
            else{
                p1 = p1 -> next;
                p2 = p2 -> next;
            }
        }
        return p2;
    }
};
```