### 解题思路
1、先通过快慢指针找到链表中间，并在此过程中将结点依次入栈；
2、在得到中点后，慢指针继续往后遍历，同时取出栈顶元素，与链表结点进行比较，如果不同就返回false，退出遍历，如果慢指针就继续往后；
3、注意：链表结点个数为奇数时，慢指针需要多走一步，跳过中间结点。

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
        if(head == nullptr) return true;

        ListNode* slow = head;
        ListNode* fast = head;
        
        ListNode* node;
        stack<ListNode*> nodeStack;
        
        while(fast != nullptr && fast->next != nullptr) {
            nodeStack.push(slow);
            slow = slow->next;
            fast = fast->next->next;
        }
        if(fast != nullptr) {
            slow = slow->next;
        }

        while(slow != nullptr) {
            node = nodeStack.top();
            nodeStack.pop();
            if(node->val != slow->val) {
                return false;
            }
            slow = slow->next;
        }

        return true;
    }
};
```