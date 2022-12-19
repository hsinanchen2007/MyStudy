### 解题思路
核心思路：设置pre、curr两个指针，两个指针同时向前移动，判断curr指向节点的内容是否等于val
执行用时 :24 ms, 在所有 C++ 提交中击败了6.35%的用户
内存消耗 :8.4 MB, 在所有 C++ 提交中击败了100.00%的用户
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
    ListNode* deleteNode(ListNode* head, int val) {
        ListNode*pre=head;
        ListNode*curr=head->next;
        if(head->val==val)return curr;
        while(curr!=NULL){
            if(curr->val==val){
                pre->next=curr->next;
                return head;
            }
            else{
                curr=curr->next;
                pre=pre->next;
            }
        }
        return head;
    }
};
```