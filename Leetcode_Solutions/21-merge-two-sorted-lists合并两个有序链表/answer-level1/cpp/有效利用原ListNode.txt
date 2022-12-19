### 解题思路
注意使用原来的node，new很消耗时间。

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *result = new ListNode(0);
        ListNode *move = result;
        while(l1 != nullptr || l2 != nullptr){
            if(l1 != nullptr && l2 == nullptr){
                move->next = l1;
                l1 = l1->next;
            }else if(l2 != nullptr && l1 == nullptr){
                move->next = l2;
                l2 = l2->next;
            }else if(l1 != nullptr && l2 != nullptr){
                if(l1->val == l2->val){
                    move->next = l1;
                    l1 = l1->next;
                }else if(l1->val > l2->val){
                    move->next = l2;
                    l2 = l2->next;
                }else if(l1->val < l2->val){
                    move->next = l1;
                    l1 = l1->next;
                }
            }
            move = move->next;
        }
        return result->next;
    }
};
```