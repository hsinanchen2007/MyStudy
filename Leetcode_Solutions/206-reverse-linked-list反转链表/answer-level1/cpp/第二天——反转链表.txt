### 解题思路
- 使用哨兵节点，不断迭代实现链表的反转
- 需要常数空间，O(n)的时间复杂度。
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
        if(!head) return head;

        ListNode* sentinel = new ListNode(0);  //哨兵节点
        sentinel->next = head;   
        ListNode* tail = head;
        ListNode* p = nullptr;

        while(tail->next) tail = tail->next;  //标记结尾
        while(sentinel->next != tail){
            p = sentinel->next;
            sentinel->next = sentinel->next->next;
            p->next = tail->next;
            tail->next = p;
        }
        return sentinel->next;
    }
};
```