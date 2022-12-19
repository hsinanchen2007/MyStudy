### 解题思路
1、定义两List，分别指向左右；
2、针对左链表收集val < 3的节点,针对右边聊收集val >= 3的节点;
3、合并两各链表，同时将右链表next清空;
4、返回；

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
    ListNode* partition(ListNode* head, int x) {
        ListNode* smallList = new ListNode(0);
        ListNode* bigList = new ListNode(0);
        ListNode* smallTmp = smallList;
        ListNode* bigTmp = bigList;
        while (head != nullptr) {
            if (head->val < x) {
                smallTmp->next = new ListNode(head->val);
                smallTmp = smallTmp->next;
            } else {
                bigTmp->next = new ListNode(head->val);
                bigTmp = bigTmp->next;
            }
            head = head->next;
        }
        bigTmp->next = nullptr;
        smallTmp->next = bigList->next;
        // smallList = smallList->next;
        return  smallList->next;
    }
};
```