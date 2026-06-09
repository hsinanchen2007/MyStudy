### 解题思路
关键: 构建链表元素的滑窗，窗内的所有元素一样，随后，只保留第一个元素

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
        if(!head) return NULL;
        ListNode* pre = new ListNode(-1);
        pre->next = head;
        while(head->next){
            ListNode* r = new ListNode(-1);
            r = head->next;
            if(head->val != r->val){
                head = head->next;
            }else{
                int target = head->val;
                while(r->next && r->next->val == target){
                    r = r->next;
                }
                head->next = r->next;
            }
        }
        return pre->next;
    }
};
```
执行用时 : 12 ms , 在所有 C++ 提交中击败了 67.57% 的用户 
内存消耗 : 8.3 MB , 在所有 C++ 提交中击败了 100.00% 的用户