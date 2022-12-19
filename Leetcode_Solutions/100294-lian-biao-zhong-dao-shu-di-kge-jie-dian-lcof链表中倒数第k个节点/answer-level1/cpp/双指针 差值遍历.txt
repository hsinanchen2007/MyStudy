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
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode *q, *p;
        q = head;
        p = head;
        while((--k) != 0) //前后指针差k 当后者的next指针为NULL时 前者即在倒数第k个；
        {
            p = p -> next;
        }
        while((p -> next) !=NULL)
        {
            q = q -> next;
            p = p -> next;
        }
        return q;
    }
};
```