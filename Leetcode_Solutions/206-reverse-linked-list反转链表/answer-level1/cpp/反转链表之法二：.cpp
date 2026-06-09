### 解题思路
此处撰写解题思路
方法二：用循环的方法一步步置换；具体的理解根据调试代码就好了。
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
    ListNode* reverseList(ListNode* head)
     {
        ListNode *newHead = NULL;
        while(head!=NULL)
        {
            ListNode *temp =head->next;
            head->next = newHead;
            newHead = head;
            head = temp;
        }
        return newHead;
    }
    
};
```