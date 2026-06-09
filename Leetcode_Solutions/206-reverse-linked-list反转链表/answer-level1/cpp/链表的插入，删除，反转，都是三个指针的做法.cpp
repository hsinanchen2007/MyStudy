### 解题思路
只要是链表插入，反转等问题，都是用pre, cur, post三个指针的方式去做，这道题也不例外

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
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = NULL;
        //pre->next = head;
        ListNode* post = new ListNode(-1);
        if(!head || !head->next) return head;
        post = head->next;
        while(head){
            post = head->next;
            head->next = pre;
            //
            pre = head;
            head = post;
        }
        return pre;
    }
};
```

### 结果
执行用时 : 8 ms , 在所有 C++ 提交中击败了 70.22% 的用户 
内存消耗 : 7.8 MB , 在所有 C++ 提交中击败了 100.00% 的用户