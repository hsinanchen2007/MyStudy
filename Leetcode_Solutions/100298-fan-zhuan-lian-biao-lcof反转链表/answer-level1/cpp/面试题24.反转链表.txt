### 解题思路
核心思路：头插法，在原链表前新建一个blank节点，依次将原链表head之后的每个节点插在blank之后
执行用时 :12 ms, 在所有 C++ 提交中击败了20.59%的用户
内存消耗 :7.9 MB, 在所有 C++ 提交中击败了100.00%的用户
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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL){
            return NULL;
        }
        if(head->next==NULL){
            return head;
        }
        ListNode*blank=new ListNode(0);
        blank->next=head;
        ListNode*pre=head->next,*cur=head->next->next;
        while(cur!=NULL){
            pre->next=blank->next;
            blank->next=pre;
            pre=cur;
            cur=cur->next;
        }
        pre->next=blank->next;
        blank->next=pre;
        head->next=NULL;
        return blank->next;
    }
};
```