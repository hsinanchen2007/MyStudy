### 解题思路
使用快慢指针，快指针走两步，慢指针走一步，慢指针所经过的所有节点都加入到栈中
快指针最后为最后一个节点或为null，若为最后一个节点，说明节点个数为奇数，否则为偶数
注意为奇数时，中间那个数不需要比较
根据栈的特性，逐个比较后半段节点和栈顶的值即可
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
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return true;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* slow = dummy;
        ListNode* fast = dummy;
        stack<int> s;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            s.push(slow->val);
        }
        if(!fast) s.pop();
        ListNode* p = slow->next;
        while(p){
            if(s.top() != p->val)
                return false;
            s.pop();
            p = p->next;
        }
        return true;
        
    }
};
```