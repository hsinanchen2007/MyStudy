### 解题思路
通过快慢指针找到链表的中点，然后将后半段反转，判断前后是否相等。将快指针初始位置设为第二个节点，方便后续奇偶链的处理。
![image.png](https://pic.leetcode-cn.com/0106b15370fa782cb8ef0bd18f9a4141762478c942d04059d4b9488c10b178d8-image.png)

![image.png](https://pic.leetcode-cn.com/28f55bf2feabf4606ce5a7f49db9b3be43e5059bccd614efe8d8b0ab0c3aabd7-image.png)

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
        if (!head || !head->next) return true;
        ListNode* fast = head->next, *slow = head;
        //将slow指针移动到中间位置
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* newhead = new ListNode(-1);
        ListNode* curNode = slow->next;
        while (curNode) {
            ListNode* nextNode = curNode->next;
            curNode->next = newhead->next;
            newhead->next = curNode;
            curNode = nextNode;
        }
        slow->next = NULL;
        newhead = newhead->next;
        //比较是否相等
        while (head && newhead) {
            if (head->val != newhead->val) return false;
            head = head->next;
            newhead = newhead->next;
        }
        return true;
    }
};
```