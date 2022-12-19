### 解题思路
题没读懂 整明白了就是相对位置不变 大小分两边。。。
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
    ListNode* partition(ListNode* head, int x) {
         ListNode* big = new ListNode(-1);
         ListNode* let = new ListNode(-1);
         ListNode *ret = let,*da = big;
         while(head != NULL){
             if(head->val < x){
                 let->next = head;
                 let = let->next;
             }else{
                 big->next = head;
                 big = big->next;
             }
             head = head->next;
         }
         big->next = NULL;
         let->next = da->next;
         return ret->next;
    }
};
```