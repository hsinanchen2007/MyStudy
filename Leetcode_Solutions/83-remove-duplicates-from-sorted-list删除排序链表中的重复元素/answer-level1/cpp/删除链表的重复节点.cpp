### 解题思路
关键有两点失误：1.如果头指针为空，直接返回头指针（这是惯例，记住）2. 为了保证最后的重复元素也能被删除，每次都要置空已有的不重复链表尾。

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
        if (head != nullptr){
            int temp = head->val;
        ListNode * ptr1 = head;
        ListNode * ptr2 = head;
        while(ptr2->next != nullptr){
              ptr2 = ptr2 ->next;
              ptr1->next = nullptr;
              if(ptr1->val != ptr2->val){
                  ptr1->next = ptr2;
                  ptr1 = ptr1->next;
              }
        }
        } 
        return head;
    }
};
```