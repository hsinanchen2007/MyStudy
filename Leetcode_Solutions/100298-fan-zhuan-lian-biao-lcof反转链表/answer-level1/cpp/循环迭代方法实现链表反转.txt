### 解题思路
此处撰写解题思路
循环迭代实现，保存head指向的下一个节点，并将head指向定义的尾节点，尾节点变更为当前节点，
下一节点变更为head节点

时间复杂度O(n)
空间复杂度O(1)
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

        ListNode* tmp=NULL;
        ListNode* tail=NULL;
        if((head==NULL)||(head->next==NULL))return head;
        while(head) {
            tmp = head->next;
            head->next = tail;
            tail=head;
            head=tmp;
        }
        return tail;
    }

    
};
```