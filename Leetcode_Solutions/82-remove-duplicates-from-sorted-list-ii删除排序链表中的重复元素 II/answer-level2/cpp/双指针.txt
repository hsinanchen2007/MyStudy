### 解题思路
1.快指针负责遍历整个列表
2.慢指针负责选取不重复的数字
注意：head也是有值的

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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* ptr = new ListNode(0);
        ListNode* first = ptr;
        first->next = head;
        ListNode* second = head;
        if(second==NULL) return head;
        int temp1 = second->val;
        bool dup = false;
        while (second->next!=NULL) {
            if(second->next->val==temp1){
                dup = true;
                first->next = NULL;
            }
            else{
                if(dup){
                    first->next = second->next;
                }
                else{
                    first = first->next;
                }
                dup = false;
                
            }
            second = second->next;
            temp1 = second->val;
        }
        return ptr->next;
    }
};
```