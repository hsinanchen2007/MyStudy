### 解题思路
我们可以自己添加一个首元节点，这样可以方便我们操作，我们通过一个循环遍历，来找出与所给值相同的节点，然后用后一个覆盖(即删除)；

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
        auto dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* pre = dummy;
        while(pre&&pre->next){
            if(pre->next->val == val) {
                pre->next = pre->next->next;
                break;
            } 
            pre = pre->next;   
        }
        return dummy->next;

    }
};
```