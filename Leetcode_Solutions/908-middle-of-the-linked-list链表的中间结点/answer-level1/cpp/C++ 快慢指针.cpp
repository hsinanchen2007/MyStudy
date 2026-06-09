### 解题思路
1.建立虚拟头结点dummy，指向头结点head；
2.定义快慢指针分别为fast,slow，在fast指针不为空的情况下，每次两步，slow指针每次一步；
3.当fast变为NULL时，while循环停止。此时slow指针正好指向的是中间节点，返回即可。
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
    ListNode* middleNode(ListNode* head) {
        if(!head) return head;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *fast = dummy,*slow = dummy;
        while(fast){
            fast = fast->next;
            slow = slow->next;
            if(fast) fast = fast->next;
            else break;
        }
        return slow;
    }
};
```