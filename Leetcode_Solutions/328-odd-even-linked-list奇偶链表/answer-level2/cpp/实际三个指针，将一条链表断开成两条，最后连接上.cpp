### 解题思路
此处撰写解题思路

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
    ListNode* oddEvenList(ListNode* head) {
         //特殊性判断
        if(head == nullptr || head->next == nullptr) return head;

        //初始化四个指针
        ListNode* headodd = head;
        ListNode* odd = head;
        ListNode* headeven = head->next;
        ListNode* even = head->next;

        while( even != nullptr && even->next != nullptr)
        {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = headeven;
        return head;
    }
};
```