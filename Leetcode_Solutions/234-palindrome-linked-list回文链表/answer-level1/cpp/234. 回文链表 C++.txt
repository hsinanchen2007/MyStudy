### 解题思路
1.将链表全部压入栈中，在逐步出栈，即出栈的为链表的逆序，与原链表比较，若结点元素一一对应则返回true，若有不同则返回false。

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
        stack<int> s;
        ListNode* currentNode = head;
        while(currentNode){
            s.push(currentNode->val);
            currentNode = currentNode->next;
        }
        currentNode = head;
        while(currentNode){
            if(currentNode->val != s.top()){
                return false;
            }
            s.pop();
            currentNode = currentNode->next;
        }
        return true;
    }
};
```