### 解题思路
通过快慢双指针取到链表的中间位置
用栈将链表的后半部分的值反转存储
将链表前半部分的值依次与栈内元素比较，完全一致则该链表为回文链表
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
        if(head==NULL) return true;
        ListNode* fast = head->next;
        ListNode* slow = head;
        while(fast!=NULL&&fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        stack<int>slowVal;
        while(slow!=NULL){
            slowVal.push(slow->val);
            slow=slow->next;
        }
        return isEqual(head,slowVal);
    }
    bool isEqual(ListNode* head,stack<int> st){
        while(head!=NULL&&!st.empty()){
            if(head->val!=st.top()){
                return false;
            }
            head=head->next;
            st.pop();
        }
        return true;
    }
};
```