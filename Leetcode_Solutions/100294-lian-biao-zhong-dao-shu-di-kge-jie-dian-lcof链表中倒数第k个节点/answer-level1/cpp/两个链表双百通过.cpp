### 解题思路
一个链表求解长度n，第二个链表讲前（n-k）个数据丢弃，得到的就是想要的结果

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
        ListNode* res = head;
        int size = 0;
        while(res != NULL){
            size++;
            res = res->next;
        }
        int count = 0;
        while(count < size - k){
            head = head->next;
            count++;
        }
        return head;
    }
};
```